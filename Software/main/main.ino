#include "lmx2572.h"

// Put default values here. Get these values from the last commit.
ref_set_t ref;
vco_set_t vco;
out_set_t out;
fsk_set_t fsk;

void setup() {
  // put your setup code here, to run once:
  LMX2572 rf_synthesizer;
  
  rf_synthesizer.ref_path(ref);
  rf_synthesizer.vco_setting(vco);
  rf_synthesizer.output_setting(out);
  rf_synthesizer.fsk_setting(fsk);
  rf_synthesizer.calculate_validate();
}

void loop() {
  // put your main code here, to run repeatedly:

}
