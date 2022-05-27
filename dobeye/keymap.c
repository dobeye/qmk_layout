/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "keymap_steno.h"
#include "keymap_hebrew.h"

void eeconfig_init_user() {
    steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

enum custom_keycodes {
    LANGSWITCH = SAFE_RANGE
};

enum layers {
    _RSTHD = 0,
    _HEBREW,
    _HUMHEB,
    _NAV,
    _SYM,
    _FUNCTION,
    _STENO,
};


// Aliases for readability

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define NUMHEB   MO(_HUMHEB)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define SHFT_GRV MT(MOD_LSFT, KC_GRAVE)
#define ALT_BSLS MT(MOD_LALT, KC_BSLS)
#define RSFT_EQL MT(MOD_RSFT, KC_EQL)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: RSTHD
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   J  |   C  |   Y  |   F  |   K  |                              |   Z  |   L  |   ,  |   U  |   Q  | Alt/\  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   R  |   S  |   T  |   H  |   D  |                              |   M  |   N  |   A  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |LShift/`|   /  |   V  |   G  |   P  |   B  |  { [ | Steno|  |F-keys|  ] } |   X  |   W  |   .  |   ;  |   -  |RShift/=|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute | Super| Bksp |   E  |  Nav |  |Hebrew| Space| Enter| Nums | Home |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RSTHD] = LAYOUT(
     KC_TAB  ,  KC_J ,  KC_C   ,  KC_Y  ,   KC_F ,   KC_K ,                                            KC_Z ,   KC_L ,KC_COMM,   KC_U ,  KC_Q ,ALT_BSLS,
     CTL_ESC ,  KC_R ,  KC_S   ,  KC_T  ,   KC_H ,   KC_D ,                                            KC_M ,   KC_N ,  KC_A ,   KC_I ,  KC_O ,CTL_QUOT,
     SHFT_GRV,KC_SLSH,  KC_V   ,  KC_G  ,   KC_P ,   KC_B , KC_LBRC,TG(_STENO),    FKEYS  , KC_RBRC ,  KC_X ,   KC_W ,KC_DOT , KC_SCLN,KC_MINS,RSFT_EQL,
                                 KC_MUTE, KC_LGUI, KC_BSPC,   KC_E , NAV       , LANGSWITCH, KC_SPC ,KC_ENT,   SYM  ,KC_HOME
    ),

/*
 * Base Layer: Hebrew
 *
 * ,-------------------------------------------.                               ,-------------------------------------------.
 * |  Tab   |   ;  |   ס  |   א  |   ק  |   .  |                               |  ,  |   ע  |   נ  |   פ   |   ₪  |   Alt   |
 * |--------+------+------+------+------+------|                               |------+------+------+------+------+--------|
 * |Ctrl/Esc|   מ  |   ב  |   ה  |   י  |   /  |                               |   ' |   ו  |   ר   |   ל  |   ת  |   Ctrl  |
 * |--------+------+------+------+------+------+-------------.  ,--------------+------+------+------+------+------+--------|
 * | LShift |   ד  |   כ  |   צ  |   ט  |NumHeb|  { [ | Steno|  |F-keys|  ] }  |NumHeb|   ז  |   ג  |   ח  |   ש  |  RShift  |
 * `----------------------+------+------+------+------+------|  |-------+------+------+------+------+----------------------'
 *                        | Mute | Super| Bksp | Space|  Nav |  |English| Space| Enter| Nums | Home |
 *                        |      |      |      |      |      |  |       |      |      |      |      |
 *                        `----------------------------------'  `-----------------------------------'
 */
    [_HEBREW] = LAYOUT(
     _______ , IL_SCLN,  IL_PE, IL_NUN , IL_AYIN,  IL_COMM ,                                       IL_DOT, IL_QOF,IL_ALEF, IL_SMKH,IL_SHKL, KC_LALT,
     _______ , IL_TAV , IL_LAMD,  IL_RESH , IL_VAV, IL_QUOT ,                                       IL_SLSH, IL_YOD ,IL_HE, IL_BET, IL_MEM, KC_RCTL,
     KC_LSFT , IL_TET, IL_TSDI, IL_KAF, IL_DALT,  NUMHEB , IL_RBRC , _______ , _______ , IL_LBRC ,NUMHEB, IL_SHIN,IL_HET, IL_GIML ,IL_ZAYN, KC_RSFT,
                                _______, _______, _______, KC_SPC  , _______ , _______ , _______ ,_______, _______, _______
    ),

/*
 * Base Layer: NumHeb
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   :  |   ף  |   X  |   X  |   <  |                              |   >  |   7  |   8  |   9  |   -  |    /   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   ם  |   X  |   X  |   X  |   "  |                              |   ?  |   4  |   5  |   6  |   +  |   *    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   X  |   ץ  |   ך  |   X   |NumHeb|   {  |  (  |  |    )  |  }  |NumHeb|   1  |   2  |   3  |   .  |  Enter |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute | Super| Bksp | Space|   X  |  |   X  | Space|   0  | Nums | Home |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_HUMHEB] = LAYOUT(
     _______ ,IL_COLN,  IL_FPE, XXXXXXX, XXXXXXX, IL_RABK,                                       IL_LABK,  KC_P7 , KC_P8 ,  KC_P9 ,KC_PMNS, KC_PSLS,
     _______ ,IL_FMEM, XXXXXXX, XXXXXXX, XXXXXXX, IL_DQUO,                                       IL_QUES,  KC_P6 , KC_P5 ,  KC_P6 ,KC_PPLS, KC_PAST,
     _______ ,XXXXXXX, IL_FKAF, IL_FTSD, XXXXXXX, _______, IL_RCBR,IL_RPRN,     IL_LPRN, IL_LCBR,_______,  KC_P1 , KC_P2 ,  KC_P3 ,KC_PDOT, KC_PENT,
                                _______, _______, _______, _______,XXXXXXX,     XXXXXXX, _______, KC_P0 , _______,_______
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |NumLck|  | Boot |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute |      |      |      |  Nav |  |      |      |      |      | Home |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM , QK_BOOT, XXXXXXX,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute |      |      |      |      |  |      |      |      | Nums | Home |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, XXXXXXX, XXXXXXX, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |F_Keys|      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute |      |      |      |      |  |      |      |      |      | Home |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      XXXXXXX,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , XXXXXXX,                                     XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
      XXXXXXX,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
    ),

/*
 * Base Layer: Plover
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   #  |   #  |   #  |   #  |   #  |                              |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |                              |   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   S  |   K  |   w  |   R  |   *  |      |      |  |      |      |   *  |   R  |   B  |   G  |   S  |   Z    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute |      |   A  |   O  | RSTHD|  |      |   E  |   U  |      | Home |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_STENO] = LAYOUT(
      XXXXXXX, STN_N1 , STN_N2 , STN_N3 , STN_N4 , STN_N5 ,                                    STN_N6 , STN_N7 , STN_N8 , STN_N9 ,  STN_NA , STN_NB ,
      XXXXXXX, STN_S1 , STN_TL , STN_PL , STN_HL , STN_ST1,                                    STN_ST3, STN_FR , STN_PR , STN_LR ,  STN_TR , STN_DR ,
      XXXXXXX, STN_S2 , STN_KL , STN_WL , STN_RL , STN_ST2,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, STN_ST4, STN_RR , STN_BR , STN_GR ,  STN_SR , STN_ZR ,
                                 _______, XXXXXXX, STN_A  ,STN_O,TO(_RSTHD), XXXXXXX,  STN_E , STN_U, XXXXXXX, _______
    ),

/*
 * Base Layer: Plover
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   #  |   #  |   #  |   #  |   #  |                              |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |                              |   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   S  |   K  |   w  |   R  |   *  |   O  |Hebrew|  |      |   E  |   *  |   R  |   B  |   G  |   S  |   Z    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |   A  | RSTHD|  |      |   U  | AltGr|      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _RSTHD:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _HEBREW:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _HUMHEB:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _STENO:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LANGSWITCH:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(" "));
                layer_invert(_HEBREW);
            }
            break;
    }
    return true;
};
