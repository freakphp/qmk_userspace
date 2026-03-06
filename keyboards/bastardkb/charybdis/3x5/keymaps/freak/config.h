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
 *
 * BastardKB Splinky shield pins for Charybdis 3x5:
 *   Cols: GP28, GP21, GP6, GP7, GP8
 *   Rows: GP26, GP5, GP4, GP9
 *
 * Svlinky v0.2 swap: GP26 -> GP24
 * (GP27 is not a matrix pin; it moved to VIK bus)
 * ------------------------------------------------- */

#undef MATRIX_COL_PINS
#undef MATRIX_ROW_PINS

#define MATRIX_COL_PINS { GP28, GP21, GP6, GP7, GP8 }
#define MATRIX_ROW_PINS { GP24, GP5, GP4, GP9 }

/* -------------------------------------------------
 * Svlinky v0.2: remap Splinky SPI0 → VIK SPI1
 *
 * Parent charybdis config.h (Splinky shield, SPI0):
 *   SCK=GP22, MOSI=GP23, MISO=GP20, CS=GP16
 *
 * Svlinky v0.2 VIK bus (SPI1):
 *   SCK=GP14, MOSI=GP15, MISO=GP12, CS=GP13
 * ------------------------------------------------- */
#undef SPI_DRIVER
#define SPI_DRIVER SPID1

#undef SPI_SCK_PIN
#define SPI_SCK_PIN GP14

#undef SPI_MOSI_PIN
#define SPI_MOSI_PIN GP15

#undef SPI_MISO_PIN
#define SPI_MISO_PIN GP12

#undef POINTING_DEVICE_CS_PIN
#define POINTING_DEVICE_CS_PIN GP13

/* VIK I2C (I2C1 on RP2040) */
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP10
#define I2C1_SCL_PIN GP11

/* VIK extra GPIO (analog-capable on svlinky v0.2) */
#define VIK_GPIO_1 GP26
#define VIK_GPIO_2 GP27

/* WS2812 data routed through VIK on GP16.
 * Parent keyboard.json sets GP0 for Splinky;
 * parent config.h had GP16 as POINTING_DEVICE_CS (now GP13). */
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
