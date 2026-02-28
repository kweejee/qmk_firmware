#include QMK_KEYBOARD_H
#include "version.h"
#include "os_detection.h"

enum layers {
    BASE,
    MAC, // red
    VIM, // green
    SYMB,  // blue
    MACVIM, // red+green
};

enum custom_keycodes {
  VRSN = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |L(SYM)|           |T(MAC)|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  | Bspace |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Escape |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  =   |           |   \  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~~~  | lCtl | lGui | lAlt | Spce |                                       | Spce | rAlt | rGui | rCtl | ~~~  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | F5   | Prnt |       |      |       |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | Home |       | PgUp |       |      |
 *                                 |L(VIM)| Enter|------|       |------| L(VIM)|Enter |
 *                                 |      |      | End  |       | PgDn |       |      |
 *                                 `--------------------'       `---------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand                                                                     right hand
  KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    MO(SYMB),      TG(MAC), KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS,
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_LBRC,       KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_BSPC,
  KC_ESCAPE, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_QUOT,
  KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_EQUAL,      KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,
  KC_LCTL,   KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,                                  KC_SPC,  KC_RALT, KC_RGUI, KC_RCTL, KC_NO,
                                                KC_F6,   KC_PSCR,       KC_NO,   KC_NO,
                                                         KC_HOME,       KC_PGUP,
                                        MO(VIM), KC_ENT, KC_END,        KC_PGDN, MO(VIM), KC_ENT
),
[MAC] = LAYOUT_ergodox_pretty(
  // left hand                                                       right hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  KC_LCTL, KC_LGUI, KC_LOPT, KC_LGUI, _______,                                         _______, KC_RGUI, KC_ROPT, KC_RGUI, KC_RCTL,
                                               _______, LCSG(KC_4),  _______, _______,
                                                        _______,     _______,
                                      MO(MACVIM), _______, _______,  _______, MO(MACVIM), _______
),
/* Keymap VIM Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      | Redo |      |      |           |      |      | Undo | Home |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CAPS   | End  |      |Delete|      |      |------|           |------|  ←   |  ↓   |  ↑   |  →   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |VolDn |VolUp |       |BriDn |BriUp |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[VIM] = LAYOUT_ergodox_pretty(
  // left hand                                                         right hand
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,      KC_F6,       KC_F7,   KC_F8,   KC_F9,      KC_F10,  KC_F11,  KC_F12,  _______,
  _______, _______, _______, _______, LCS(KC_Z), _______,    _______,     _______, _______, LCTL(KC_Z), KC_HOME, _______, _______, _______,
  KC_CAPS, KC_END,  _______, KC_DEL,  _______,   _______,                          KC_LEFT, KC_DOWN,    KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______,   _______,    _______,     _______, _______, _______,    _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                           _______,    _______, _______, _______, _______,
                                                 KC_VOLD,    KC_VOLU,     KC_BRID, KC_BRIU,
                                                             _______,     _______,
                                      _______,   LGUI(KC_L), _______,     _______, _______, _______
),
[MACVIM] = LAYOUT_ergodox_pretty(
  // left hand                                                                 right hand
  _______, KC_F1,         KC_F2,   KC_F3,   KC_F4,     KC_F5,     KC_F6,       KC_F7,   KC_F8,   KC_F9,      KC_F10,        KC_F11,  KC_F12,  _______,
  _______, _______,       _______, _______, LSG(KC_Z), _______,   _______,     _______, _______, LGUI(KC_Z), LGUI(KC_LEFT), _______, _______, _______,
  KC_CAPS, LGUI(KC_RGHT), _______, KC_DEL,  _______,   _______,                         KC_LEFT, KC_DOWN,    KC_UP,         KC_RGHT, _______, _______,
  _______, _______,       _______, _______, _______,   _______,   _______,     _______, _______, _______,    _______,       _______, _______, _______,
  _______, _______,       _______, _______, _______,                                             _______,    _______,       _______, _______, _______,
                                                       KC_VOLD,   KC_VOLU,     KC_BRID, KC_BRIU,
                                                                  _______,     _______,
                                             _______,  LCG(KC_Q), _______,     _______, _______, _______
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * | EE_CLR  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       EE_CLR, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

#if defined(OS_DETECTION_ENABLE)
// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
    os_variant_t host = detected_host_os();
    if (host == OS_MACOS || host == OS_IOS) {
        layer_on(MAC);
    }
};
#endif
