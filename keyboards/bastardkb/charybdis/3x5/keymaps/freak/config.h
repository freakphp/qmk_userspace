/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

/* -------------------------------------------------
 * Svlinky v0.2 matrix pin translation for Charybdis
 * (Splinky shield wiring, but on Svlinky v0.2)
 *
 * Splinky typical:
 *   Cols: GP27, GP28, GP21, GP6, GP7, GP8
 *   Rows: GP29, GP26, GP5, GP4, GP9
 *
 * Svlinky v0.2 swap:
 *   GP27 -> GP18
 *   GP26 -> GP24
 * ------------------------------------------------- */
#undef MATRIX_COL_PINS
#undef MATRIX_ROW_PINS
#define MATRIX_COL_PINS { GP28, GP21, GP6, GP7, GP8 }
#define MATRIX_ROW_PINS { GP24, GP5, GP4, GP9 }

/* -----------------------------
 * VIK bus pins (svlinky)
 * ----------------------------- */

// SPI for VIK modules (trackball/trackpad sensors, displays, etc.)
#define VIK_SPI_SCK_PIN  GP14
#define VIK_SPI_MOSI_PIN GP15
#define VIK_SPI_MISO_PIN GP12
#define VIK_SPI_CS       GP13

// I2C for VIK modules
#define VIK_I2C_SDA_PIN  GP10
#define VIK_I2C_SCL_PIN  GP11

// Extra VIK GPIO (svlinky v0.2)
#define VIK_GPIO_1       GP26
#define VIK_GPIO_2       GP27

/* -----------------------------
 * RGB over VIK (your SK6812MINI-E chain)
 * ----------------------------- */

// “RGB Data Out from VIK” on svlinky is GP16.
#undef WS2812_DI_PIN
#define WS2812_DI_PIN GP16

#ifdef VIA_ENABLE
/* VIA configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 7
#endif // VIA_ENABLE

#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE
