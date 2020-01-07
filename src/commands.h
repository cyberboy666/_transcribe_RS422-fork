#include <stdint.h>
#include <Arduino.h>

namespace OUTTYPE{
    const uint8_t BUTTON = 0;
    const uint8_t SLIDER = 1;
    const uint8_t SLIDER_TWO = 2;
    const uint8_t SWITCH = 3;
}

namespace AVE55{

// const char A_BUS_MOSAIC_OFF[8] = "VDE:076"; // Video digital effect
// const char A_BUS_MOSAIC_STEP_1[8] = "VDE:077"; // Video digital effect
// const char A_BUS_MOSAIC_STEP_2[8] = "VDE:078"; // Video digital effect
// const char A_BUS_MOSAIC_STEP_3[8] = "VDE:079"; // Video digital effect
// const char A_BUS_MOSAIC_STEP_4[8] = "VDE:080"; // Video digital effect
// const char A_BUS_MOSAIC_STEP_5[8] = "VDE:081"; // Video digital effect

const char MIX_MODE[8] = "VMX:000"; // Mix mode /Out of WIPE
const char A_B_MIX_LEVEL[8] = "VMM:179"; // xx	POTENTIOMETRE 00=A, FF=B
const char CENTER_WIPE[8] = "VPS:218";

const char A_BUS_SOURCE_1[8] = "VCP:200"; // BUTTON
// const char A_BUS_SOURCE_2[8] = "VCP:201"; // BUTTON
// const char A_BUS_SOURCE_3[8] = "VCP:202"; // BUTTON
// const char A_BUS_SOURCE_4[8] = "VCP:203"; // BUTTON
const char A_BUS_BACK_COLOR[8] = "VCP:204"; // BUTTON


/*
const char MIX_MODE[8] = "VMX:000"; // Mix mode /Out of WIPE
const char WIPE_SQUARE_CORNER_UL[8] = "VWP:001"; // Video Wipe Pattern
const char WIPE_SQUARE_CORNER_DL[8] = "VWP:002"; // Video Wipe Pattern
const char WIPE_SQUARE_CORNER_DR[8] = "VWP:003"; // Video Wipe Pattern
const char WIPE_SQUARE_CORNER_UR[8] = "VWP:004"; // Video Wipe Pattern
const char WIPE_BLIND_L[8] = "VWP:005"; // Video Wipe Pattern
const char WIPE_BLIND_D[8] = "VWP:006"; // Video Wipe Pattern
const char WIPE_BLIND_R[8] = "VWP:007"; // Video Wipe Pattern
const char WIPE_BLIND_U[8] = "VWP:008"; // Video Wipe Pattern
const char WIPE_TRIANGLE_CORNER_UL[8] = "VWP:009"; // Video Wipe Pattern
const char WIPE_TRIANGLE_CORNER_DL[8] = "VWP:010"; // Video Wipe Pattern
const char WIPE_TRIANGLE_CORNER_DR[8] = "VWP:011"; // Video Wipe Pattern
const char WIPE_TRIANGLE_CORNER_UR[8] = "VWP:012"; // Video Wipe Pattern
const char WIPE_TRIANGLE_L[8] = "VWP:013"; // Video Wipe Pattern
const char WIPE_TRIANGLE_D[8] = "VWP:014"; // Video Wipe Pattern
const char WIPE_TRIANGLE_R[8] = "VWP:015"; // Video Wipe Pattern
const char WIPE_TRIANGLE_U[8] = "VWP:016"; // Video Wipe Pattern
const char WIPE_SQUARE[8] = "VWP:017"; // Video Wipe Pattern
const char WIPE_CIRCLE[8] = "VWP:018"; // Video Wipe Pattern
const char WIPE_OVALE[8] = "VWP:019"; // Video Wipe Pattern
const char WIPE_LOSANGE[8] = "VWP:020"; // Video Wipe Pattern
const char WIPE_I[8] = "VWP:021"; // Video Wipe Pattern
const char WIPE_MINUS[8] = "VWP:022"; // Video Wipe Pattern
const char WIPE_PLUS[8] = "VWP:023"; // Video Wipe Pattern
const char WIPE_SPECIAL_24[8] = "VWP:024"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_25[8] = "VWP:025"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_26[8] = "VWP:026"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_27[8] = "VWP:027"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_28[8] = "VWP:028"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_29[8] = "VWP:029"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_30[8] = "VWP:030"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_31[8] = "VWP:031"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_32[8] = "VWP:032"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_33[8] = "VWP:033"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_34[8] = "VWP:034"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_35[8] = "VWP:035"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_36[8] = "VWP:036"; // Video Special Wipe Pattern
const char WIPE_SPECIAL_37[8] = "VWP:037"; // Video Special Wipe Pattern
const char DIRECTION_ONE_WAY[8] = "VWD:040"; // Wipe Direction
const char DIRECTION_REVERSE[8] = "VWD:041"; // Wipe Direction
const char EDGE_NONE[8] = "VWB:042"; // Edge/Border
const char EDGE_BORDER[8] = "VWB:043"; // Edge/Border	! 50
const char EDGE_SOFT[8] = "VWB:044"; // Edge/Border	! 50
const char MULTI_BASIC[8] = "VWM:045"; // Multi Wipe
const char MULTI_1[8] = "VWM:046"; // Multi Wipe	! 47
const char MULTI_2[8] = "VWM:047"; // Multi Wipe	! 47
const char MULTI_3[8] = "VWM:048"; // Multi Wipe	! 47
const char MODE_NORMAL[8] = "VWM:049"; // Wipe Mode
const char MODE_COMPRESSION[8] = "VWM:050"; // Wipe Mode
const char MODE_SLIDE[8] = "VWM:051"; // Wipe Mode
const char MODE_PAIR[8] = "VWM:052"; // Wipe Mode
const char MODE_SLIDE_COMPRESSION[8] = "VW:053"; // Wipe Mode
const char OPERATION_OVER[8] = "VW:054"; // Wipe Operation
const char OPERATION_REMOVE[8] = "VW:055"; // Wipe Operation
const char OPERATION_FLIP[8] = "VW:056"; // Wipe Operation
const char OPERATION_PUSH[8] = "VW:057"; // Wipe Operation
const char SPEDGE_NONE[8] = "VWB:061"; // Special Edge
const char SPEDGE_BORDER[8] = "VWB:062"; // Special Edge
const char SPEDGE_SOFT[8] = "VWB:063"; // Special Edge
const char A_BUS_STROBO_OFF[8] = "VDE:070"; // Video digital effect
const char A_BUS_STROBO_STEP_1[8] = "VDE:071"; // Video digital effect
const char A_BUS_STROBO_STEP_2[8] = "VDE:072"; // Video digital effect
const char A_BUS_STROBO_STEP_3[8] = "VDE:073"; // Video digital effect
const char A_BUS_STROBO_STEP_4[8] = "VDE:074"; // Video digital effect
const char A_BUS_STROBO_STEP_5[8] = "VDE:075"; // Video digital effect
const char A_BUS_MOSAIC_OFF[8] = "VDE:076"; // Video digital effect
const char A_BUS_MOSAIC_STEP_1[8] = "VDE:077"; // Video digital effect
const char A_BUS_MOSAIC_STEP_2[8] = "VDE:078"; // Video digital effect
const char A_BUS_MOSAIC_STEP_3[8] = "VDE:079"; // Video digital effect
const char A_BUS_MOSAIC_STEP_4[8] = "VDE:080"; // Video digital effect
const char A_BUS_MOSAIC_STEP_5[8] = "VDE:081"; // Video digital effect
const char A_BUS_PAINT_OFF[8] = "VDE:082"; // Video digital effect
const char A_BUS_PAINT_STEP_1[8] = "VDE:083"; // Video digital effect
const char A_BUS_PAINT_STEP_2[8] = "VDE:084"; // Video digital effect
const char A_BUS_PAINT_STEP_3[8] = "VDE:085"; // Video digital effect
const char A_BUS_PAINT_STEP_4[8] = "VDE:086"; // Video digital effect
const char A_BUS_NEGATIVE_OFF[8] = "VDE:087"; // Video digital effect
const char A_BUS_NEGATIVE_ON[8] = "VDE:088"; // Video digital effect
const char A_BUS_FIELD_STILL_MODE[8] = "VDE:089"; // Video digital effect
const char A_BUS_FRAME_STILL_MODE[8] = "VDE:090"; // Video digital effect
const char A_BUS_COLOR_CORRECTOR_OFF[8] = "VDE:091"; // Video digital effect
const char A_BUS_COLOR_CORRECTOR_ON[8] = "VDE:092"; // Video digital effect
const char A_BUS_CHROMA_LEVEL[8] = "VDE:093"; // xx	Video digital effect 	xx =(ASCII HEX 01H_17H
const char B_BUS_STROBO_OFF[8] = "VDE:094"; // Video digital effect
const char B_BUS_STROBO_STEP_1[8] = "VDE:095"; // Video digital effect
const char B_BUS_STROBO_STEP_2[8] = "VDE:096"; // Video digital effect
const char B_BUS_STROBO_STEP_3[8] = "VDE:097"; // Video digital effect
const char B_BUS_STROBO_STEP_4[8] = "VDE:098"; // Video digital effect
const char B_BUS_STROBO_STEP_5[8] = "VDE:099"; // Video digital effect
const char B_BUS_MOSAIC_OFF[8] = "VDE:100"; // Video digital effect
const char B_BUS_MOSAIC_STEP_1[8] = "VDE:101"; // Video digital effect
const char B_BUS_MOSAIC_STEP_2[8] = "VDE:102"; // Video digital effect
const char B_BUS_MOSAIC_STEP_3[8] = "VDE:103"; // Video digital effect
const char B_BUS_MOSAIC_STEP_4[8] = "VDE:104"; // Video digital effect
const char B_BUS_MOSAIC_STEP_5[8] = "VDE:105"; // Video digital effect
const char B_BUS_PAINT_OFF[8] = "VDE:106"; // Video digital effect
const char B_BUS_PAINT_STEP_1[8] = "VDE:107"; // Video digital effect
const char B_BUS_PAINT_STEP_2[8] = "VDE:108"; // Video digital effect
const char B_BUS_PAINT_STEP_3[8] = "VDE:109"; // Video digital effect
const char B_BUS_PAINT_STEP_4[8] = "VDE:110"; // Video digital effect
const char B_BUS_NEGATIVE_OFF[8] = "VDE:111"; // Video digital effect
const char B_BUS_NEGATIVE_ON[8] = "VDE:112"; // Video digital effect
const char B_BUS_FIELD_STILL_MODE[8] = "VDE:113"; // Video digital effect
const char B_BUS_FRAME_STILL_MODE[8] = "VDE:114"; // Video digital effect
const char B_BUS_COLOR_CORRECTOR_OFF[8] = "VDE:115"; // Video digital effect
const char B_BUS_COLOR_CORRECTOR_ON[8] = "VDE:116"; // Video digital effect
const char B_BUS_CHROMA_LEVEL[8] = "VDE:117"; // xx	Video digital effect 	xx =(ASCII HEX 01H_17H
const char AUDIO_MIX_LEVEL_GLOBAL_FOLLOW_ON[8] = "AML:120"; // Audio
const char AUDIO_MIX_LEVEL_GLOBAL_FOLLOW_OFF[8] = "AML:121"; // Audio
const char AUDIO_LEVEL_SOURCE_1[8] = "ALV:122"; // xx	Audio	(xx is ASCII 00H_1AH
const char AUDIO_LEVEL_SOURCE_2[8] = "ALV:123"; // xx	Audio	(xx is ASCII 00H_1AH
const char AUDIO_LEVEL_SOURCE_3[8] = "ALV:124"; // xx	Audio	(xx is ASCII 00H_1AH
const char AUDIO_LEVEL_SOURCE_4[8] = "ALV:125"; // xx	Audio	(xx is ASCII 00H_1AH
const char AUDIO_MIX_LEVEL_SOURCE_4_FOLLOW_ON[8] = "AML:126"; // Audio
const char AUDIO_MIX_LEVEL_SOURCE_4_FOLLOW_OFF[8] = "AML:127"; // Audio
const char VIDEO_FADE_ON[8] = "VFD:130"; // Fade
const char VIDEO_FADE_OFF[8] = "VFD:131"; // Fade
const char AUDIO_FADE_ON[8] = "VFD:132"; // Fade
const char AUDIO_FADE_OFF[8] = "VFD:133"; // Fade
const char TITTLE_FADE_ON[8] = "VFD:134"; // Fade
const char TITTLE_FADE_OFF[8] = "VFD:135"; // Fade
const char FADE_TO_WHITE[8] = "VFD:136"; // Fade
const char FADE_TO_BLACK[8] = "VFD:137"; // Fade
const char FADE_TO_COLOR[8] = "VFD:138"; // Fade
const char BACK_COLOR_WHITE[8] = "VBC:140"; // Set background color
const char BACK_COLOR_YELLOW[8] = "VBC:141"; // Set background color
const char BACK_COLOR_CYAN[8] = "VBC:142"; // Set background color
const char BACK_COLOR_GREEN[8] = "VBC:143"; // Set background color
const char BACK_COLOR_MAGENTA[8] = "VBC:144"; // Set background color
const char BACK_COLOR_RED[8] = "VBC:145"; // Set background color
const char BACK_COLOR_BLUE[8] = "VBC:146"; // Set background color
const char BACK_COLOR_BLACK[8] = "VBC:147"; // Set background color
const char BACK_COLOR_USER_COLOR[8] = "VBC:148"; // Set background color	set by 174
const char EDGE_COLOR_WHITE[8] = "VEC:150"; // Set edge color
const char EDGE_COLOR_YELLOW[8] = "VEC:151"; // Set edge color
const char EDGE_COLOR_CYAN[8] = "VEC:152"; // Set edge color
const char EDGE_COLOR_GREEN[8] = "VEC:153"; // Set edge color
const char EDGE_COLOR_MAGENTA[8] = "VEC:154"; // Set edge color
const char EDGE_COLOR_RED[8] = "VEC:155"; // Set edge color
const char EDGE_COLOR_BLUE[8] = "VEC:156"; // Set edge color
const char EDGE_COLOR_BLACK[8] = "VEC:157"; // Set edge color
const char EDGE_COLOR_USER_COLOR[8] = "VEC:158"; // Set edge color	set by 175
const char COLOR_MODE_NORMAL[8] = "VBG:160"; // Color Mode
const char COLOR_MODE_VERTICAL[8] = "VBG:161"; // Color Mode
const char COLOR_MODE_HORIZONTAL[8] = "VBG:162"; // Color Mode
const char COLOR_MODE_LINES[8] = "VBG:163"; // Color Mode
const char COLOR_MODE_PALETTE[8] = "VBG:164"; // Color Mode
const char TITLE_COLOR_INTERNAL_BACK_COLOR[8] = "VTC:165"; // Title colr	internal color _ using back color
const char TITLE_COLOR_EXTERNAL[8] = "VTC:166"; // Title color	external color _ controlled by titler
const char TITLE_EDGE_PATTERN_0_OFF[8] = "VTE:167"; // Tittle pattern
const char TITLE_EDGE_PATTERN_1[8] = "VTE:168"; // Tittle pattern
const char TITLE_EDGE_PATTERN_2[8] = "VTE:169"; // Tittle pattern
const char TITLE_EDGE_PATTERN_3[8] = "VTE:170"; // Tittle pattern
const char TITLE_EDGE_PATTERN_4[8] = "VTE:171"; // Tittle pattern
const char TITLE_EDGE_PATTERN_5[8] = "VTE:172"; // Tittle pattern
const char BACK_COLOR_MANUAL[8] = "VB:174"; // xxyy	Set user color xx = B_Y (ASCII HEX 00H_FFH) yy = R_Y (ASCII HEX 00H_FFH
const char EDGE_COLOR_MANUAL[8] = "VE:175"; // xxyy	Set user color xx = B_Y (ASCII HEX 00H_FFH) yy = R_Y (ASCII HEX 00H_FFH
const char A_B_MIX_LEVEL[8] = "VM:179"; // xx	POTENTIOMETRE 00=A, FF=B
const char A_BUS_EFFECT_ON[8] = "VDE:180"; // BUTTON
const char A_BUS_EFFECT_OFF[8] = "VDE:181"; // BUTTON
const char B_BUS_EFFECT_ON[8] = "VDE:182"; // BUTTON
const char B_BUS_EFFECT_OFF[8] = "VDE:183"; // BUTTON
const char A_BUS_STILL_ON[8] = "VDE:184"; // BUTTON
const char A_BUS_STILL_OFF[8] = "VDE:185"; // BUTTON
const char B_BUS_STILL_ON[8] = "VDE:186"; // BUTTON
const char B_BUS_STILL_OFF[8] = "VDE:187"; // BUTTON
const char SPEED_SET[8] = "VAS:190"; // xx	POTENTIOMETRE	xx =(ASCII HEX 01H_FFH
const char FADE_BUTTON[8] = "VF:191"; // BUTTON
const char TAKE_BUTTON[8] = "VMA:192"; // BUTTON
const char BACK_COLOR_COLOR_BARS[8] = "VBC:197"; // test
const char BACK_COLOR_NOT_COLOR_BARS[8] = "VBC:198"; // test
const char RESET_TO_FACTORY_SETTINGS[8] = "ZRS:199"; // Reset
const char A_BUS_SOURCE_1[8] = "VCP:200"; // BUTTON
const char A_BUS_SOURCE_2[8] = "VCP:201"; // BUTTON
const char A_BUS_SOURCE_3[8] = "VCP:202"; // BUTTON
const char A_BUS_SOURCE_4[8] = "VCP:203"; // BUTTON
const char A_BUS_BACK_COLOR[8] = "VCP:204"; // BUTTON
const char B_BUS_SOURCE_1[8] = "VCP:205"; // BUTTON
const char B_BUS_SOURCE_2[8] = "VCP:206"; // BUTTON
const char B_BUS_SOURCE_3[8] = "VCP:207"; // BUTTON
const char B_BUS_SOURCE_4[8] = "VCP:208"; // BUTTON
const char B_BUS_BACK_COLOR[8] = "VCP:209"; // BUTTON
const char WIPE_MIX_BUTTON[8] = "VMX:210"; // BUTTON
const char THRESHOLD_LUM_KEY[8] = "VMX:211"; // xx	BUTTON	(xx = ASCII HEX 00H FFH
const char LUM_KEY[8] = "VMX:212"; // BUTTON
const char CHROMA_KEY[8] = "VMX:213"; // BUTTON
const char CHROMA_SET[8] = "VCS:214"; // xxyyzz	BUTTON	3 couleurs en mémoire ?
const char UNDO[8] = "ZUD:215"; // BUTTON
const char ENTER[8] = "ZEN:216"; // BUTTON
const char COLOR_CORECT[8] = "VPS:217"; // xxyy	POSITION
const char CENTER_WIPE[8] = "VPS:218"; // xxyy	POSITION	(xx = horizontal) (yy _ vertical) (ASCII HEX 00H_FFH
const char SCENE_GRABER[8] = "VPS:219"; // xxyy	POSITION
*/
}
