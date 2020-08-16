/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  left ctrl,  alt,      shift,     f keys
        | knob 1: toggle layer0/1 |            | knob 2: vol dn/up 
        | press:                  | f4         | press: mute       
        | f1                      | f2         | f3                
        | media previous          | play/pause | media next        
     */
    [0] = LAYOUT(
        KC_NO    ,   MEH(KC_F4),   KC_MUTE,
        MEH(KC_F1),  MEH(KC_F2) ,  MEH(KC_F3),
        KC_MPRV,     KC_MPLY,      KC_MNXT
    ),
    /* LAYER1
        | RESET | F11 | F12 |
        | F8    | F9  | F10 |
        | F5    | F6  | F7  |
     */
    [1] = LAYOUT(
        RESET     ,  MEH(KC_F11),  MEH(KC_F12),
        MEH(KC_F8),  MEH(KC_F9) ,  MEH(KC_F10),
        MEH(KC_F5),  MEH(KC_F6) ,  MEH(KC_F7)
    ),
};
uint8_t selected_layer = 0;
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
			switch (index) {
				case 0:
					if (!clockwise && selected_layer  < 10) {
						selected_layer ++;
					} else if (clockwise && selected_layer  > 0){
						selected_layer --;
					}
				layer_clear();
				layer_on(selected_layer);
			}			
		}
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}
