#include "lmx2572.h"
#include <SPI.h>

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
 #define REG_R29   0x1D
 #define REG_R30   0x1E
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
 #define DEF_REG_R1    0x0808
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
 * Register Operations
 */
 #define LMX_R0_POWERDOWN               ((0x01) << 0)
 #define LMX_R0_RESET                   ((0x01) << 1)
 #define LMX_R0_MUXOUT_LD_SEL           ((0x01) << 2)
 #define LMX_R0_FCAL_EN                 ((0x01) << 3)
 #define LMX_R0_OUT_MUTE                ((0x01) << 9)
 #define LMX_R0_ADD_HOLD                ((0x01) << 11)
 #define LMX_R0_FCAL_HPFD(x)            (((x) & 0x03) << 7)
 #define LMX_R0_FCAL_LPFD(x)            (((x) & 0x03) << 5)
 #define LMX_R5_IPBUF_TYPE              ((0x01) << 11)
 #define LMX_R5_IPBUF_TERM              ((0x01) << 12)
 #define LMX_R6_LDO_DLY(x)              (((x) & 0x1F) << 11)
 #define LMX_R7_OUT_FORCE               ((0x01) << 14)
 #define LMX_R8_VCO_DACISET_FORCE       ((0x01) << 14)
 #define LMX_R8_VCO_CAPCTRL_FORCE       ((0x01) << 11)
 #define LMX_R9_MULT_HI                 ((0x01) << 14)
 #define LMX_R9_OSC_2X                  ((0x01) << 12)
 #define LMX_R10_MULT(x)                (((x) & 0x1F) << 7)
 #define LMX_R11_PLL_R(x)               (((x) & 0xFF) << 4)
 #define LMX_R12_PLL_R_PRE(x)           (((x) & 0xFFF) << 0)
 #define LMX_R14_CPG(x)                 (((x) & 0x0F) << 3)
 #define LMX_R16_VCO_DACISET(x)         (((x) & 0x1FF) << 0)
 #define LMX_R17_VCO_DACISET_STRT(x)    (((x) & 0x1FF) << 0)
 #define LMX_R19_VCO_CAPCTRL(x)         (((x) & 0xFF) << 0)
 #define LMX_R20_VCO_SEL(x)             (((x) & 0x07) << 11)
 #define LMX_R20_VCO_SEL_FORCE          ((0x01) << 10)
 #define LMX_R34_PLL_N(x)               (((x) & 0x07) << 0)
 #define LMX_R36_PLL_N(x)               (((x) & 0xFFFF) << 0) 
 #define LMX_R37_MASH_SEEN_EN           ((0x01) << 15)
 #define LMX_R38_PLL_DEN(x)             (((x) & 0xFFFF) << 0)
 #define LMX_R39_PLL_DEN(x)             (((x) & 0xFFFF) << 0)
 #define LMX_R40_MASH_SEED(x)           (((x) & 0xFFFF) << 0)
 #define LMX_R41_MASH_SEED(x)           (((x) & 0xFFFF) << 0)
 #define LMX_R42_PLL_NUM(x)             (((x) & 0xFFFF) << 0)
 #define LMX_R43_PLL_NUM(x)             (((x) & 0xFFFF) << 0)
 #define LMX_R44_OUTA_PWR(x)            (((x) & 0x3F) << 8)
 #define LMX_R44_OUTA_PD                ((0x01) << 6)
 #define LMX_R44_OUTB_PD                ((0x01) << 7)
 #define LMX_R44_MASH_RESET_N           ((0x01) << 5)
 #define LMX_R44_MASH_ORDER(x)          (((x) & 0x07) << 0)
 #define LMX_R45_OUTA_MUX(x)            (((x) & 0x03) << 11)
 #define LMX_R45_OUTB_PWR(x)            (((x) & 0x3F) << 0)
 #define LMX_R46_OUTB_MUX(x)            (((x) & 0x03) << 0)
 #define LMX_R59_LD_TYPE                ((0x01) << 0)
 #define LMX_R60_LD_DLY(x)              (((x) & 0xFFFF) << 0)
 #define LMX_R75_CHDIV(x)               (((x) & 0x1F) << 6)
 #define LMX_R78_VCO_CAPCTRL_STRT(x)    (((x) & 0xFF) << 1)
 #define LMX_R110_rb_VCO_SEL            ((0x07) << 5)
 #define LMX_R111_rb_VCO_CAPCTRL        ((0xFF) << 0)
 #define LMX_R112_rb_VCO_DACISET        ((0x1FF) << 0)
 #define LMX_R114_FSK_EN                ((0x01) << 10)
 #define LMX_R114_FSK_SPI_LEVEL(x)      (((x) & 0x03) << 5)
 #define LMX_R114_FSK_SPI_DEV_SEL(x)    (((x) & 0x07) << 2)
 #define LMX_R114_FSK_MODE_SEL(x)       (((x) & 0x03) << 0)
 #define LMX_R115_FSK_DEV_SCALE(x)      (((x) & 0x1F) << 3)
 #define LMX_R116_FSK_DEV0(x)           (((x) & 0xFFFF) << 0)
 #define LMX_R117_FSK_DEV1(x)           (((x) & 0xFFFF) << 0)
 #define LMX_R118_FSK_DEV2(x)           (((x) & 0xFFFF) << 0)
 #define LMX_R119_FSK_DEV3(x)           (((x) & 0xFFFF) << 0)
 #define LMX_R120_FSK_DEV4(x)           (((x) & 0xFFFF) << 0)
 #define LMX_R121_FSK_DEV5(x)           (((x) & 0xFFFF) << 0)
 #define LMX_R122_FSK_DEV6(x)           (((x) & 0xFFFF) << 0)
 #define LMX_R123_FSK_DEV7(x)           (((x) & 0xFFFF) << 0)
 #define LMX_R124_FSK_SPI_FAST_DEV(x)   (((x) & 0xFFFF) << 0)

void LMX2572::LMX2572(void)
{
  SPI.beginTransaction(SPISettings(16000000, MSBFIRST, SPI_MODE0));
  SPI.endTransaction();
  R[0] |= (LMX_R0_RESET | DEF_REG_R0);
  lmx_write(REG_R0, R[0]);
}

void LMX2572::lmx_write(uint8_t address, uint16_t data)
{
  address &= ~((0x01) << 7);
  SPI.beginTransaction();
  digitalWrite(init.csb, LOW);
  SPI.transfer(address);
  SPI.transfer16(data);
  digitalWrite(init.csb, HIGH);
  SPI.endTransaction();
}

uint16_t LMX2572::lmx_read(uint16_t address)
{
  uint16_t read_value = 0;
  address |= ((0x01) << 7);
  SPI.beginTransaction();
  digitalWrite(init.csb, LOW);
  SPI.transfer(address);
  read_value = SPI.transfer16(0);
  digitalWrite(init.csb, HIGH);
  SPI.endTransaction();
  return read_value;
}

int LMX2572::ref_path(ref_set_t ref_ex)
{
  ref = ref_ex;
  int fpd = ref.Fosc * ref.osc_2x * ref.pll_r_pre * ref.pll_r * ref.mult;

  // Set Reference Path Registers
  if (ref.osc_2x == 2) {
    R[9] = (DEF_REG_R9 | LMX_R9_OSC_2X);
  }
  else {
    R[9] = DEF_REG_R9;
  }
  if (ref.Fosc * ref.osc_2x * ref.pll_r_pre * ref.mult > 100)
  {
    R[9] |= LMX_R9_MULT_HI;
  }
  R[10] = (DEF_REG_R10 | LMX_R10_MULT(ref.mult));
  R[11] = (DEF_REG_R11 | LMX_R11_PLL_R(ref.pll_r));
  R[12] = (DEF_REG_R12 | LMX_R11_PLL_R(ref.pll_r_pre));

  // Set other parameters
  R[0] = (DEF_REG_R0 | LMX_R0_FCAL_HPFD(2) | LMX_R0_FCAL_LPFD(0));
  R[0] &= ~LMX_R0_MUXOUT_LD_SEL;
  R[1] = DEF_REG_R1;
  R[5] = DEF_REG_R5;
  R[14] = (DEF_REG_R14 | LMX_R14_CPG(4));
  R[29] = 0;
  R[30] = 0x18A6;
  
  lmx_write(REG_R0, R[0]);
  lmx_write(REG_R1, R[1]);
  lmx_write(REG_R5, R[5]);
  lmx_write(REG_R14, R[14]);
  lmx_write(REG_R29, R[29]);
  lmx_write(REG_R30, R[30]);
  lmx_write(REG_R9, R[9]);
  lmx_write(REG_R10, R[10]);
  lmx_write(REG_R11, R[11]);
  lmx_write(REG_R12, R[12]);
  return fpd;
}

void LMX2572::vco_setting(vco_set_t vco_ex)
{
  vco = vco_ex;
  R[34] = (DEF_REG_R34 | LMX_R34_PLL_N(vco.pll_n >> 16));
  R[36] = (DEF_REG_R36 | LMX_R36_PLL_N(vco.pll_n));
  R[38] = (vco.pll_den & 0xFFFF0000 >> 16);
  R[39] = (vco.pll_den & 0xFFFF);;
  R[42] = (vco.pll_num & 0xFFFF0000 >> 16);
  R[43] = (vco.pll_num & 0xFFFF);

  lmx_write(REG_R34, R[34]);
  lmx_write(REG_R36, R[36]);
  lmx_write(REG_R38, R[38]);
  lmx_write(REG_R39, R[39]);
  lmx_write(REG_R42, R[42]);
  lmx_write(REG_R43, R[43]);
}

void LMX2572::out_setting(out_set_t out_ex)
{
  out = out_ex;
  R[44] = (DEF_REG_R44 | LMX_R44_MASH_ORDER(3));
  R[44] &= ~LMX_R44_MASH_RESET_N;
  R[45] = DEF_REG_R45 | LMX_R45_OUTA_MUX(out.out_mux_a);
  R[52] = 0x0421;
  R[57] = 0x0020;
  
  lmx_write(REG_R44, R[44]);
  lmx_write(REG_R45, R[45]);
  lmx_write(REG_R52, R[52]);
  lmx_write(REG_R57, R[57]);
}

void LMX2572::fsk_setting(fsk_set_t fsk_ex)
{
  fsk = fsk_ex;
  R[114] = (DEF_REG_R114 | LMX_R114_FSK_EN | LMX_R114_FSK_SPI_LEVEL(fsk.fsk_level) | LMX_R114_FSK_MODE_SEL(fsk.fsk_type));
  R[115] = (DEF_REG_R115 | LMX_R115_FSK_DEV_SCALE(fsk.fsk_scale));

  lmx_write(REG_R114, R[114]);
  lmx_write(REG_R115, R[115]);
}

void LMX2572::fsk(uint16_t deviation)
{
  R[124] = deviation;

  lmx_write(REG_R124, R[124]);
}

void LMX2572::calibrate(void)
{
  R[0] |= LMX_R0_FCAL_EN;

  lmx_write(REG_R0, R[0]);
  delay(100);
}