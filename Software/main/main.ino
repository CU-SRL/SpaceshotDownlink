#include "lmx2572.h"

// Put default values here. Get these values from the last commit.
ref_set_t ref;
vco_set_t vco;
out_set_t out;
fsk_set_t fsk;

void setup() {
  // put your setup code here, to run once:
  LMX2572 rf_synthesizer;

  ref.osc_2x = 1;
  ref.pll_r_pre = 13;
  ref.mult = 25;
  ref.pll_r = 1;

  vco.pll_n = 64;
  vco.pll_num = 0;
  vco.pll_den = 1;

  out.out_mux_a = VCO;
  out.out_mux_b = CHDIV;
  out.chdiv = 2;
  out.out_pwr_a = 1;
  out.out_pwr_b = 1;
  out.out_pd_a = true;
  out.out_pd_b = false;

  fsk.fsk_scale = 20,
  fsk.fsk_type = fsk_spi_fast;
  fsk.fsk_level = 2;

  rf_synthesizer.ref_path(ref);
  rf_synthesizer.vco_setting(vco);
  rf_synthesizer.output_setting(out);
  rf_synthesizer.fsk_setting(fsk);
  rf_synthesizer.calculate_validate();
}

void loop() {
  // put your main code here, to run repeatedly:

}
