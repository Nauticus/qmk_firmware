/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

#define ORYX_CONFIGURATOR

#undef TAPPING_TERM
#define TAPPING_TERM 175

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

#define ONESHOT_TAP_TOGGLE 1  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 20000  /* Time (in ms) before the one shot key is released */
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define PERMISSIVE_HOLD_PER_KEY

// #undef MOUSEKEY_DELAY
// #define MOUSEKEY_DELAY          0
// #undef MOUSEKEY_INTERVAL
// #define MOUSEKEY_INTERVAL       16
// #undef MOUSEKEY_WHEEL_INTERVAL
// #define MOUSEKEY_WHEEL_INTERVAL 90
// #undef MOUSEKEY_WHEEL_DELAY
// #define MOUSEKEY_WHEEL_DELAY    0
// #undef MOUSEKEY_MAX_SPEED
// #define MOUSEKEY_MAX_SPEED      4
// #undef MOUSEKEY_TIME_TO_MAX
// #define MOUSEKEY_TIME_TO_MAX    0
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_WHEEL_DELAY
#undef MOUSEKEY_WHEEL_INTERVAL
#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX

#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_MOVE_DELTA 1
#define MOUSEKEY_MAX_SPEED 20
#define MOUSEKEY_TIME_TO_MAX 40
#define MOUSEKEY_WHEEL_DELAY 10
#define MOUSEKEY_WHEEL_INTERVAL 80
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
