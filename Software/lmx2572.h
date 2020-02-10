/*
 * LMX2572 SPI Instruction Library
 * Contains addresses of all the required registers
 * and commands required to conduct at least 4 FSK
 */

/*
 * LMX2572 Register Addresses
 */
 #define REG_R0    0x00
 #define REG_R5    0x05
 #define REG_R6    0x06
 #define REG_R7    0x07
 #define REG_R8    0x08
 #define REG_R9    0x09
 #define REG_R10   0x0A
 #define REG_R11   0x0B
 #define REG_R12   0x0C
 #define REG_R14   0x0E
 #define REG_R16   0x10
 #define REG_R17   0x11
 #define REG_R19   0x13
 #define REG_R20   0x14
 #define REG_R34   0x22
 #define REG_R36   0x24
 #define REG_R37   0x25
 #define REG_R38   0x26
 #define REG_R39   0x27
 #define REG_R40   0x28
 #define REG_R41   0x29
 #define REG_R42   0x2A
 #define REG_R43   0x2B
 #define REG_R44   0x2C
 #define REG_R45   0x2D
 #define REG_R46   0x2E
 #define REG_R59   0x3B
 #define REG_R60   0x3C
 #define REG_R75   0x4B
 #define REG_R110  0x6E
 #define REG_R111  0x6F
 #define REG_R112  0x70
 #define REG_R114  0x72
 #define REG_R115  0x73
 #define REG_R116  0x74
 #define REG_R117  0x75
 #define REG_R118  0x76
 #define REG_R119  0x77
 #define REG_R120  0x78
 #define REG_R121  0x79
 #define REG_R122  0x7A
 #define REG_R123  0x7B
 #define REG_R124  0x7C

/*
 * LMX2572 Register Default Values
 */
 #define DEF_REG_R0    0x221C
 #define DEF_REG_R5    0x30C8
 #define DEF_REG_R6    0xC802
 #define DEF_REG_R7    0x00B2
 #define DEF_REG_R8    0x2000
 #define DEF_REG_R9    0x0004
 #define DEF_REG_R10   0x10F8
 #define DEF_REG_R11   0xB018
 #define DEF_REG_R12   0x5001
 #define DEF_REG_R14   0x1840
 #define DEF_REG_R16   0x0080
 #define DEF_REG_R17   0x0096
 #define DEF_REG_R19   0x27B7
 #define DEF_REG_R20   0x3048
 #define DEF_REG_R34   0x0010
 #define DEF_REG_R36   0x0028
 #define DEF_REG_R37   0x0205
 #define DEF_REG_R38   0xFFFF
 #define DEF_REG_R39   0xFFFF
 #define DEF_REG_R40   0x0000
 #define DEF_REG_R41   0x0000
 #define DEF_REG_R42   0x0000
 #define DEF_REG_R43   0x0000
 #define DEF_REG_R44   0x22A2
 #define DEF_REG_R45   0xC622
 #define DEF_REG_R46   0x07F0
 #define DEF_REG_R59   0x0001
 #define DEF_REG_R60   0x03E8
 #define DEF_REG_R75   0x0800
 #define DEF_REG_R110  0x0000
 #define DEF_REG_R111  0x0000
 #define DEF_REG_R112  0x0000
 #define DEF_REG_R114  0x7800
 #define DEF_REG_R115  0x0000
 #define DEF_REG_R116  0x0000
 #define DEF_REG_R117  0x0000
 #define DEF_REG_R118  0x0000
 #define DEF_REG_R119  0x0000
 #define DEF_REG_R120  0x0000
 #define DEF_REG_R121  0x0000
 #define DEF_REG_R122  0x0000
 #define DEF_REG_R123  0x0000
 #define DEF_REG_R124  0x0000

/* 
 *  LMX2572 Structure for ease of usage
 */
 typedef struct {
  uint16_t R0;
  uint16_t R5;
  uint16_t R6;
  uint16_t R7;
  uint16_t R8;
  uint16_t R9;
  uint16_t R10;
  uint16_t R11;
  uint16_t R12;
  uint16_t R14;
  uint16_t R16;
  uint16_t R17;
  uint16_t R19;
  uint16_t R20;
  uint16_t R34;
  uint16_t R36;
  uint16_t R37;
  uint16_t R38;
  uint16_t R39;
  uint16_t R40;
  uint16_t R41;
  uint16_t R42;
  uint16_t R43;
  uint16_t R44;
  uint16_t R45;
  uint16_t R46;
  uint16_t R59;
  uint16_t R60;
  uint16_t R75;
  uint16_t R110;
  uint16_t R111;
  uint16_t R112;
  uint16_t R114;
  uint16_t R115;
  uint16_t R116;
  uint16_t R117;
  uint16_t R118;
  uint16_t R119;
  uint16_t R120;
  uint16_t R121;
  uint16_t R122;
  uint16_t R123;
  uint16_t R124;
 } LMX2572_TypeDef;

/*
 * Register Operations
 */
 #define LMX_R0_POWERDOWN
 #define LMX_R0_RESET
 #define LMX_R0_MUXOUT_LD_SEL
 #define LMX_R0_FCAL_EN
 #define LMX_R0_OUT_MUTE
 #define LMX_R0_ADD_HOLD
 #define LMX_R5_IPBUF_TYPE
 #define LMX_R5_IPBUF_TERM
 #define LMX_R6_LDO_DLY
 #define LMX_R7_OUT_FORCE
 #define LMX_R8_VCO_DACISET_FORCE
 #define LMX_R8_VCO_CAPCTRL_FORCE
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 #define LMX_R0_
 

/*---------------------------------------------------*/
/*
 * LMX2572 Structure Instance
 */
 LMX2572_TypeDef LMX2572_Data = {
  .R0 = DEF_REG_R0,
  .R5 = DEF_REG_R5,
  .R6 = DEF_REG_R6,
  .R7 = DEF_REG_R7,
  .R8 = DEF_REG_R8,
  .R9 = DEF_REG_R9,
  .R10 = DEF_REG_R10,
  .R11 = DEF_REG_R11,
  .R12 = DEF_REG_R12,
  .R14 = DEF_REG_R14,
  .R16 = DEF_REG_R16,
  .R17 = DEF_REG_R17,
  .R19 = DEF_REG_R19,
  .R20 = DEF_REG_R20,
  .R34 = DEF_REG_R34,
  .R36 = DEF_REG_R36,
  .R37 = DEF_REG_R37,
  .R38 = DEF_REG_R38,
  .R39 = DEF_REG_R39,
  .R40 = DEF_REG_R40,
  .R41 = DEF_REG_R41,
  .R42 = DEF_REG_R42,
  .R43 = DEF_REG_R43,
  .R44 = DEF_REG_R44,
  .R45 = DEF_REG_R45,
  .R46 = DEF_REG_R46,
  .R59 = DEF_REG_R59,
  .R60 = DEF_REG_R60,
  .R75 = DEF_REG_R75,
  .R110 = DEF_REG_R110,
  .R111 = DEF_REG_R111,
  .R112 = DEF_REG_R112,
  .R114 = DEF_REG_R114,
  .R115 = DEF_REG_R115,
  .R116 = DEF_REG_R116,
  .R117 = DEF_REG_R117,
  .R118 = DEF_REG_R118,
  .R119 = DEF_REG_R119,
  .R120 = DEF_REG_R120,
  .R121 = DEF_REG_R121,
  .R122 = DEF_REG_R122,
  .R123 = DEF_REG_R123,
  .R124 = DEF_REG_R124,
 };
 
 LMX2572_TypeDef *LMX2572 = &LMX2572_Data;
