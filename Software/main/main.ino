#include "lmx2572.h"

LMX2572 rf_synthesizer;

ref_set_t ref = {
  .osc_2x = 1,
  .pll_r_pre = 13,
  .mult = 25,
  .pll_r = 1,
};

vco_set_t vco = {
  .pll_n = 64,
  .pll_num = 0,
  .pll_den = 1,
  .Fpd = 0,
};

out_set_t out = {
  .out_mux_a = VCO,
  .out_mux_b = CHDIV,
  .chdiv = 2,
  .out_pwr_a = 1,
  .out_pwr_b = 1,
  .out_pd_a = true,
  .out_pd_b = false,
};

fsk_set_t fsk = {
  .fsk_scale = 20,
  .fsk_type = fsk_spi_fast,
  .fsk_level = 2,
}

void setup() {
  // put your setup code here, to run once:
  int fpd = rf_synthesizer.ref_path(ref);
  vco.Fpd = fpd;
  rf_synthesizer.vco_setting(vco);
  rf_synthesizer.output_setting(out);
  rf_synthesizer.fsk_setting(fsk);
  rf_synthesizer.calculate_validate();
  rf_synthesizer.write();
}

void loop() {
  // put your main code here, to run repeatedly:

}
