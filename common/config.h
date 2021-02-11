/*
This is the c configuration file for the keymap

Copyright 2021 Mike Lu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

#ifdef COMBO_ENABLE
  #define COMBO_COUNT 1
  #define COMBO_TERM 120
#endif

#define LEADER_TIMEOUT 500
#define MASTER_RIGHT
#define TAPPING_TERM 100
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define ONESHOT_TIMEOUT 3000
