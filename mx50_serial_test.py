# dependencies (Python >= 3.5):
# aioconsole==0.1.10
# pyserial==3.4
# pyserial-asyncio==0.4

import asyncio

import aioconsole
import serial
import serial_asyncio


class WJMx50(asyncio.Protocol):
    flip = False
    def __init__(self):
        self.reply = bytearray()
    
    def connection_made(self, transport):
        print('connected')
        self.transport = transport
        asyncio.ensure_future(self.repl())

    async def repl(self):
        while True:
            cmd = await aioconsole.ainput('?? ')
            self.write(cmd.encode())
        
    def write(self, cmd):
        # print('-> {}'.format(cmd))
        # msg = b'\x02' + cmd + b'\x03'
        # msg = cmd # extron mod - no start/stop bytes
        if self.flip:
            msg = b'\x01' + b'\x81' + b'\x81' + b'\x81'
            self.flip = False
        else:
            msg = b'\x01' + b'\x82' + b'\x81' + b'\x81'
            self.flip = True
        print(msg)
        self.transport.write(msg)

    def data_received(self, data):
        reply = data.strip(b'\x23')
        if not reply:
            return
        for i, byte in enumerate(reply):
            if byte == 0x15: 
                print('\n<- NAK', flush=True)
                self.prompt()
            elif byte == 0x06:
                print('\n<- ACK', flush=True)
                self.prompt()
            elif byte == 0x02:
                self.start_message()
            elif byte == 0x03:
                self.end_message()
            else:
                self.feed_message(byte)
    
    def start_message(self):
        self.reply = bytearray()

    def feed_message(self, byte):
        self.reply.append(byte)

    def end_message(self):
        print('\n<- {}'.format(bytes(self.reply)), flush=True)
        self.prompt()

    def prompt(self):
        print('?? ', end='', flush=True) 

loop = asyncio.get_event_loop()
coro = serial_asyncio.create_serial_connection(
    loop,
    WJMx50,
    '/dev/ttyUSB0',  # or whatever yr comport is
    bytesize=serial.EIGHTBITS, #.SEVENBITS, - EIGHTBITS for extron
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE
)
loop.run_until_complete(coro)
loop.run_forever()
loop.close()


'''
PARITY_NONE, PARITY_EVEN, PARITY_ODD, PARITY_MARK, PARITY_SPACE = 'N', 'E', 'O', 'M', 'S'
STOPBITS_ONE, STOPBITS_ONE_POINT_FIVE, STOPBITS_TWO = (1, 1.5, 2)
FIVEBITS, SIXBITS, SEVENBITS, EIGHTBITS = (5, 6, 7, 8)
'''