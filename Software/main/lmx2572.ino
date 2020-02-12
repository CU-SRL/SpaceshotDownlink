#include "lmx2572.h"

void lmx_write(uint8_t address, uint16_t data)
{
  address &= ~((0x01) << 7);
  SPI.beginTransaction();
  digitalWrite(chip_select, LOW);
  SPI.transfer(address);
  SPI.transfer16(data);
  digitalWrite(chip_select, HIGH);
  SPI.endTransaction();
}

uint16_t lmx_read(uint16_t address)
{
  uint16_t read_value = 0;
  address |= ((0x01) << 7);
  SPI.beginTransaction();
  digitalWrite(chip_select, LOW);
  SPI.transfer(address);
  read_value = SPI.transfer16(0);
  digitalWrite(chip_select, HIGH);
  SPI.endTransaction();
  return read_value;
}

/*
 * Function for initializing LMX2572
 */
void lmx_init(void)
{
}

/*
 * Function for resetting LMX2572
 */
void lmx_reset(void)
{
}

/*
 * Function for disabling LMX2572
 */
void lmx_disable(void)
{
}


/*
 * Function to change frequency to given frequency
 */
void lmx_change_ref_freq_settings(LMX_Frequency_t frequency)
{
}

/*
 * Function to change frequency to given frequency
 */
void lmx_change_freq_settings(LMX_Frequency_t frequency)
{
}'

/*
 * Function to shift to one of the FSK frequencies
 */
void lmx_change_to_fsk_freq(uint8_t dev_sel)
{
}
