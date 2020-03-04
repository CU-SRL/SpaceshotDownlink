#ifndef LMX2572_H_
#define LMX2572_H_

#include "Arduino.h"

typedef struct {
    int sck;
    int miso;
    int mosi;
    int csb;
} init_t;

struct ref_set_t{
    int Fosc;
    int osc_2x;
    int pll_r_pre;
    int pll_r;
    int mult;
};

typedef struct ref_set_t ref_set_t;

typedef struct {
    uint32_t pll_n;
    uint32_t pll_num;
    uint32_t pll_den;
} vco_set_t;

typedef enum {
    CHDIV,
    VCO,
    Hi_Z = 0x3,
} out_mux_t;

typedef struct {
    out_mux_t out_mux_a;
    out_mux_t out_mux_b;
    int chdiv;
    int out_pwr_a;
    int out_pwr_b;
    bool out_pd_a;
    bool out_pd_b;
} out_set_t;

typedef enum {
    fsk_spi,
    fsk_spi_fast,
} fsk_type_t;

typedef struct {
    int fsk_scale;
    fsk_type_t fsk_type;
    int fsk_level;
} fsk_set_t;

class LMX2572
{
    public:
        LMX2572(void);
        int ref_path(ref_set_t);
        void vco_setting(vco_set_t);
        void output_setting(out_set_t);
        void fsk_setting(fsk_set_t);
        void fsk_fast(uint16_t);
        void calculate_validate(void);
    private:
        void lmx_write(uint8_t address, uint16_t data);
        uint16_t lmx_read(uint16_t address);
        uint16_t R[126];
        init_t init = {10, 11, 12, 13};
        ref_set_t ref = {1, 1, 1, 1, 52};
        vco_set_t vco = {32, 0, 1};
        out_set_t out = {VCO, VCO, 2, 1, 1, true, false};
        fsk_set_t fsk = {1, fsk_spi_fast, 2};
};

#endif /* LMX2572_H_ */
