#include <keymap_spanish.h>

/*
Ebony & Ivory - Mark3
*/

#include QMK_KEYBOARD_H

#include <stdio.h>

#define ES_NTIL KC_SCLN         // Ñ
#define ES_COMM KC_COMM         // ,
#define ES_DOT  KC_DOT          // .
#define ES_MINS KC_SLSH         // -
#define ES_SLSH S(ES_7)         // /
#define ES_EQL  S(ES_0)         // =
#define ES_LABK KC_NUBS         // <
#define ES_RABK S(ES_LABK)      // >
#define ES_AT   ALGR(ES_2)      // @
#define ES_QUOT KC_MINS         // '
#define ES_TILD ALGR(ES_4)      // ~

//TapDance
#define ES_LPRN S(ES_8)         // (
#define ES_RPRN S(ES_9)         // )
#define ES_LCBR ALGR(ES_ACUT)   // {
#define ES_RCBR ALGR(ES_CCED)   // }
#define ES_PERC S(ES_5)         // %
#define ES_PIPE ALGR(ES_1)      // |
#define ES_DQUO S(ES_2)         // "
#define ES_PLUS KC_RBRC         // +
#define ES_ASTR S(ES_PLUS)      // *
#define ES_HASH ALGR(ES_3)      // #
#define ES_ACUT KC_QUOT         // ´ (dead)
#define ES_COLN S(KC_DOT)       // :
#define ES_IQUE S(ES_IEXL)      // ¿
#define ES_QUES S(ES_QUOT)      // ?
#define ES_LBRC ALGR(ES_GRV)    // [
#define ES_RBRC ALGR(ES_PLUS)   // ]

//TAPDANCE

// Tap Dance declarations
enum {
    TD_ENE,
	TD_DRS,
    TD_FAT
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for N, twice for Ñ
    [TD_ENE] = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_SCLN),
    // Tap once for U, twice for ¨
  	[TD_DRS] = ACTION_TAP_DANCE_DOUBLE(KC_U, ES_DIAE),
    // Tap once for F, twice for @
    [TD_FAT] = ACTION_TAP_DANCE_DOUBLE(KC_F, ES_AT),
};

//TAPDANCE - END

//MACRO

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ABRX:
      if (record->event.pressed) {
        SEND_STRING("Abraxas.2019");
      }
      break;
    case KC_YKOL:
      if (record->event.pressed) {
        SEND_STRING("Yakol.ps.13");
      }
      break;
  }
  return true;
}



//MACRO - END

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y, TD(TD_DRS),    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,  KC_D,TD(TD_FAT),    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, ES_ACUT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   TD(TD_ENE),    KC_M, ES_COMM,  ES_DOT, ES_MINS, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_RCTL,   MO(1), KC_LCMD,     KC_SPC,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'
                                                                                        //,KC_ALGR.
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   KC_GRV, LSFT(KC_GRV), ES_IQUE, ES_QUES, ES_DQUO, ES_HASH,                         KC_1,    KC_2,    KC_3, ES_ASTR, ES_SLSH, KC_DLR,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //, <          >          ¿        ?        "        #                               1         2        3      *       /         $
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ES_IEXL, ES_LPRN, ES_RPRN, ES_LBRC, ES_RBRC, ES_PIPE,                         KC_4,    KC_5,    KC_6, ES_PLUS, ES_MINS, KC_PERC,
  //|--------+--------+--------+--------+--------+--------|  				   |--------+--------+--------+--------+--------+--------|
  //    ¡        (        )        [         ]        |                                4        5        6       +       -         %
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ES_EXLM, ES_LCBR, ES_RCBR, ES_TILD, ES_QUOT, KC_ABRX,                         KC_7,    KC_8,    KC_9,    KC_0,  ES_DOT,  ES_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //    !         {       }      MUERTO     '         @                                7        8        9        0        .        = 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|

                                          KC_TRNS, _______, KC_TRNS,    KC_TRNS,   MO(3), KC_ALGR
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_BRMU, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BRMD, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_SLEP,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F5,   KC_F5,   KC_F5,   KC_F5,   KC_F5, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3), KC_TRNS,    KC_TRNS, _______, KC_ALGR
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.                                                                                                                                                                                                                                                                                                                                            
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______, KC_TRNS,    KC_TRNS, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_QWERTY 0
#define L_BAJA 2
#define L_SUPERIOR 4
#define L_AJUSTES 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case L_BAJA:
            oled_write_ln_P(PSTR("BAJA"), false);
            break;
        case L_SUPERIOR:
            oled_write_ln_P(PSTR("SUPERIOR"), false);
            break;
        case L_AJUSTES:
        case L_AJUSTES|L_BAJA:
        case L_AJUSTES|L_SUPERIOR:
        case L_AJUSTES|L_BAJA|L_SUPERIOR:
            oled_write_ln_P(PSTR("AJUSTES"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE
