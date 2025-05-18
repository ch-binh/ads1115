# Introduciton

This document can be used as a quick guide to select the suitable parameters for adc

### Selecting PGA and SPS:
Rules of thumb:
- The higher the Full-Scale Range: the lower the resolution, due to
    Resolution = Vref/16bit
- The higher the sampling rate SPS: less noise is filtered out due to oversampling mechanism of Delta Sigma converter.


To select the suitable SPS, refer to table 6.1 and 6.2 in the datasheet