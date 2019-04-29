#include QMK_KEYBOARD_H
#include "version.h"
#include "vim.h"

#define VERSION_STRING QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION

#define BASE 0 // default layer
#define VIM 1
#define NUMPAD 2

//enum custom_keycodes {
//  EPRM = SAFE_RANGE,
//  VRSN,
//  RGB_SLD
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   `    |   1  |   2  |   3  |   4  |   5  | L2   |           | L2   |   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Tab    |   Q  |   W  |   E  |   R  |   T  | [    |           | ]    |   Y  |   U  |   I  |   O  |   P  | Bspace |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | Escape |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;    | '      |
   * |--------+------+------+------+------+------| =    |           | \    |------+------+------+------+------+--------|
   * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | /    | RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      | Ctrl | LGUI | Alt  | Spce |                                       |  Up  | Down |   [  |   ]  | ~L1  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | F6   | Print|       | Del  |      |
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Home |       | PgUp |        |      |
   *                                 | L1   | Enter|------|       |------| L1     |Enter |
   *                                 |      |      | End  |       | PgDn |        |      |
   *                                 `--------------------'       `----------------------'
   */
  [BASE] = LAYOUT_ergodox(
    // left hand
    KC_GRAVE,      KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    MO(NUMPAD),
    KC_TAB,        KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_LBRACKET,
    KC_ESCAPE,     KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
    KC_LSHIFT,     CTL_T(KC_Z), KC_X,          KC_C,    KC_V,    KC_B,    KC_EQUAL,
    KC_NO,         KC_LCTRL,    KC_LGUI,       KC_LALT, KC_SPC,
                                                             KC_F6, KC_PSCREEN,
                                                                              KC_HOME,
                                                           MO(VIM), KC_ENTER, KC_END,
    // right hand
    MO(NUMPAD),   KC_6,    KC_7,    KC_8,    KC_9,     KC_0,        KC_MINS,
    KC_RBRACKET,  KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,        KC_BSPACE,
                  KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,     KC_QUOT,
    KC_BSLASH,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLASH,    KC_RSFT,
                  KC_SPC,  KC_RALT, KC_APP,  KC_RCTRL, KC_NO,
    KC_DEL, KC_NO,
    KC_PGUP,
    KC_PGDN, MO(VIM), KC_ENTER
  ),
  /* Keymap 2: Symbol Layer
   *
   * ,---------------------------------------------------.           ,--------------------------------------------------.
   * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
   * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |        |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
   * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | EPRM  |      |      |      |      |                                       |   0  |      |   .  |   =  |      |
   *   `-----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |Animat|      |       |Toggle|Solid |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
   *                                 |ness- |ness+ |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [NUMPAD] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
    KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
    KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
    EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 RGB_MOD, KC_TRNS,
                                                          KC_TRNS,
                                        RGB_VAD, RGB_VAI, KC_TRNS,
    // right hand
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_NO,
             KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
    KC_NO,   KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                      KC_0,    KC_NO,   KC_DOT,  KC_EQL,  KC_TRNS,
    RGB_TOG, RGB_SLD,
    KC_TRNS,
    KC_TRNS, RGB_HUD, RGB_HUI
  ),
  
  /*
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        | F1   | F2   | F3   | F4   | F5   | F6   |           | F7   | F8   | F9   | F10  | F11  | F12  |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | TAB    |      | WORD |  END |      |      |      |           |      | YANK | UNDO |      | OPEN |  PUT |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | CAPS   |      |      |  DEL |      |      |------|           |------|  ←   |  ↓   |  ↑   |  →   |      |    ⎋   |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | SHIFT  |      |      |      |VISUAL| BACK |      |           |      |      |      |      |      |      | SHIFT  |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | VOL- | VOL+ |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |SPACE |DELETE|------|       |------|ENTER |BACKSP|
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [VIM] = LAYOUT_ergodox(
    // Layer 2 Left Hand
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
    KC_TAB,  _______, VIM_W,   VIM_E,   _______, _______, _______,
    KC_CAPS, KC_END,  VIM_S,   KC_DEL,  _______, _______,
    KC_LSFT, _______, VIM_X,   VIM_C,   VIM_V,   VIM_B  , _______,
    KC_LCTL, KC_LALT, _______, _______, _______, 
                                                 KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
                                                          _______,
                                                 _______, _______, _______,


    // Layer 2 Right Hand
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  _______,
    _______, VIM_Y,   VIM_U,   KC_HOME, VIM_O,    VIM_P,   _______,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______,  _______, KC_LSFT,
    _______, _______, _______, KC_RALT, KC_RCTL,
    KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,
    _______,
    _______, _______, _______ 
  ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  if (record->event.pressed) {
//    switch (keycode) {
//      case EPRM:
//        eeconfig_init();
//        return false;
//      case VRSN:
//        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
//        return false;
//      #ifdef RGBLIGHT_ENABLE
//      case RGB_SLD:
//        rgblight_mode(1);
//        return false;
//      #endif
//    }
//  }
//  return true;
//}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool SHIFTED = (keyboard_report->mods & MOD_BIT(KC_LSFT)) |
                 (keyboard_report->mods & MOD_BIT(KC_RSFT));

  switch (keycode) {

    case VIM_A:
      if (record->event.pressed) { SHIFTED ? VIM_APPEND_LINE() : VIM_APPEND(); }
      return false;

    case VIM_B:
      if (record->event.pressed) {
        switch(VIM_QUEUE) {
          case KC_NO: VIM_BACK(); break;
          case VIM_C: VIM_CHANGE_BACK(); break;
          case VIM_D: VIM_DELETE_BACK(); break;
          case VIM_V: VIM_VISUAL_BACK(); break;
        }
      }
      return false;

    case VIM_C:
      if (record->event.pressed) {
        switch(VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_CHANGE_LINE() : VIM_LEADER(VIM_C); break;
          case VIM_C: VIM_CHANGE_WHOLE_LINE(); break;
        }
      }
      return false;

    case VIM_D:
      if (record->event.pressed) {
        switch(VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_DELETE_LINE() : VIM_LEADER(VIM_D); break;
          case VIM_D: VIM_DELETE_WHOLE_LINE(); break;
        }
      }
      return false;

    case VIM_E:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_END(); break;
          case VIM_C: VIM_CHANGE_END(); break;
          case VIM_D: VIM_DELETE_END(); break;
          case VIM_V: VIM_VISUAL_END(); break;
        }
      }
      return false;

    case VIM_H:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_LEFT(); break;
          case VIM_C: VIM_CHANGE_LEFT(); break;
          case VIM_D: VIM_DELETE_LEFT(); break;
          case VIM_V: VIM_VISUAL_LEFT(); break;
        }
      }
      return false;

//    case VIM_I:
//      if (record->event.pressed) {
//        switch (VIM_QUEUE) {
//          case KC_NO: layer_on(INSERT_MODE); break;
//          case VIM_C: VIM_LEADER(VIM_CI); break;
//          case VIM_D: VIM_LEADER(VIM_DI); break;
//          case VIM_V: VIM_LEADER(VIM_VI); break;
//        }
//      }
//      return false;

    case VIM_J:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_JOIN() : VIM_DOWN(); break;
          case VIM_C: VIM_CHANGE_DOWN(); break;
          case VIM_D: VIM_DELETE_DOWN(); break;
          case VIM_V: VIM_VISUAL_DOWN(); break;
        }
      }
      return false;

    case VIM_K:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_UP(); break;
          case VIM_C: VIM_CHANGE_UP(); break;
          case VIM_D: VIM_DELETE_UP(); break;
          case VIM_V: VIM_VISUAL_UP(); break;
        }
      }
      return false;

    case VIM_L:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_RIGHT(); break;
          case VIM_C: VIM_CHANGE_RIGHT(); break;
          case VIM_D: VIM_DELETE_RIGHT(); break;
          case VIM_V: VIM_VISUAL_RIGHT(); break;
        }
      }
      return false;

    case VIM_O:
      if (record->event.pressed) { SHIFTED ? VIM_OPEN_ABOVE() : VIM_OPEN(); }
      return false;

    case VIM_P:
      if (record->event.pressed) { SHIFTED ? VIM_PUT_BEFORE() : VIM_PUT(); }
      return false;

    case VIM_S:
      if (record->event.pressed) { SHIFTED ? VIM_CHANGE_WHOLE_LINE() : VIM_SUBSTITUTE(); }
      return false;

    case VIM_U:
      if (record->event.pressed) { VIM_UNDO(); }
      return false;

    case VIM_V:
      if (record->event.pressed) { VIM_LEADER(VIM_V); }
      return false;

    case VIM_W:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_WORD(); break;
          case VIM_C: VIM_CHANGE_WORD(); break;
          case VIM_CI: VIM_CHANGE_INNER_WORD(); break;
          case VIM_D: VIM_DELETE_WORD(); break;
          case VIM_DI: VIM_DELETE_INNER_WORD(); break;
          case VIM_V: VIM_VISUAL_WORD(); break;
          case VIM_VI: VIM_VISUAL_INNER_WORD(); break;
        }
      }
      return false;

    case VIM_X:
      if (record->event.pressed) { VIM_CUT(); }
      return false;

    case VIM_Y:
      if (record->event.pressed) { SHIFTED ? VIM_YANK_LINE() : VIM_YANK(); }
      return false;

    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) { eeconfig_init(); }
      return false;
    case VRSN:
      if (record->event.pressed) { SEND_STRING(VERSION_STRING); }
      return false;
    case RGB_SLD:
      if (record->event.pressed) { rgblight_mode(1); }
      return false;
  }

  // End by clearing the queue unless keycode is a
  // if ((record->event.pressed) &&
  //     (keycode != VIM_I ||
  //     keycode != VIM_C ||
  //     keycode != VIM_D ||
  //     keycode != VIM_V)) {
  //   VIM_LEADER(KC_NO);
  // }

  return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
