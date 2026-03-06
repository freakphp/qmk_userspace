// Svlinky v0.2 VIK bus uses SPI1 (GP14/GP15/GP12).
// The parent mcuconf.h only enables SPI0 for the Splinky shield.

#pragma once

#include_next <mcuconf.h>

#undef RP_SPI_USE_SPI1
#define RP_SPI_USE_SPI1 TRUE
