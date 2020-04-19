#include QMK_KEYBOARD_H

#define ______ KC_TRNS
#define _______ KC_TRNS
#define ________ KC_TRNS
#define _________ KC_TRNS
#define __________ KC_TRNS
#define ___________ KC_TRNS
#define ____________ KC_TRNS
#define _____________ KC_TRNS

enum custom_keycodes {
     CUSTOM_LEFT_SHIFT = SAFE_RANGE,
     MAGIC_SCOLON,
     SHIFT_LEFT_KEYS,
     MAGIC_THUMB1,
     MAGIC_THUMB2,
     KC_U_Q = SHIFT_LEFT_KEYS + KC_Q,
     KC_U_W = SHIFT_LEFT_KEYS + KC_W,
     KC_U_E = SHIFT_LEFT_KEYS + KC_E,
     KC_U_R = SHIFT_LEFT_KEYS + KC_R,
     KC_U_T = SHIFT_LEFT_KEYS + KC_T,
     KC_U_A = SHIFT_LEFT_KEYS + KC_A,
     KC_U_S = SHIFT_LEFT_KEYS + KC_S,
     KC_U_D = SHIFT_LEFT_KEYS + KC_D,
     KC_U_F = SHIFT_LEFT_KEYS + KC_F,
     KC_U_G = SHIFT_LEFT_KEYS + KC_G,
     KC_U_Z = SHIFT_LEFT_KEYS + KC_Z,
     KC_U_X = SHIFT_LEFT_KEYS + KC_X,
     KC_U_C = SHIFT_LEFT_KEYS + KC_C,
     KC_U_V = SHIFT_LEFT_KEYS + KC_V,
     KC_U_B = SHIFT_LEFT_KEYS + KC_B,
     KC_U_1 = SHIFT_LEFT_KEYS + KC_1,
     KC_U_2 = SHIFT_LEFT_KEYS + KC_2,
     KC_U_3 = SHIFT_LEFT_KEYS + KC_3,
     KC_U_4 = SHIFT_LEFT_KEYS + KC_4,
     KC_U_5 = SHIFT_LEFT_KEYS + KC_5,
    
};
// Macro Declarations
enum {
    MACRO_PIPE = 0,   //These macros can be replaced by LSFT(kc) etc..https://beta.docs.qmk.fm/reference/keycodes#modifiers
    MACRO_TILDE = 1,  
    MACRO_QUESTION = 2,
    MACRO_SHINS = 3,
    MACRO_LESS_THAN = 4,
    MACRO_GREATER_THAN = 5,

    MACRO_NUM = 10,  
    MACRO_SHNUM = 20,  
    // ..., the rest of your macros
};

#define _BL 0
#define _FL 1
#define _ML 2  
#define _SL 3  
#define _SL2 4 
#define _BR 5  
#define _BR2 6 
#define _QM 7
#define _NUMKEYS 8
#define _NUM 9
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BL] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_F14, KC_DEL,
        KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_BSPC, KC_INSERT,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_DEL, KC_F13, KC_PGUP,
        MO(_FL), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, MAGIC_SCOLON, KC_QUOT, KC_ENT, KC_PGDN,
        KC_LSFT, _______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, ______, KC_RALT, KC_UP, TG(_NUMKEYS), // Right shift disabled
        KC_LCTL, KC_LGUI, KC_LALT, MAGIC_THUMB1, MAGIC_THUMB2, KC_RCTL, KC_RALT, KC_LGUI, MO(_ML), KC_LEFT, KC_DOWN, KC_RGHT),

    [_SL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_U_1, KC_U_2, KC_U_3, KC_U_4, KC_U_5, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_1, KC_2, KC_3, KC_4, KC_5, ______, M(MACRO_PIPE), KC_MINS, KC_PLUS, _______, _______, _______, _______, _______,
        _______, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DOUBLE_QUOTE, KC_ENT, KC_UNDERSCORE, KC_EQL, _______, _______, _______, _______,
        _______, _______, KC_GRV, KC_DOT, M((MACRO_LESS_THAN)), M((MACRO_GREATER_THAN)), M(MACRO_QUESTION), KC_BSLS, KC_SLSH, ______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_FL] = LAYOUT(
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, BL_DEC, BL_TOGG, BL_INC, BL_STEP, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_CAPS, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, M(MACRO_SHINS), _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_SCLN, _______, KC_ESC, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R),
    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, _______, _______, _______, _______, _______,
        _______, M((MACRO_NUM + 1)), M((MACRO_NUM + 2)), M((MACRO_NUM + 3)), M((MACRO_NUM + 4)), M((MACRO_NUM + 5)), M((MACRO_NUM + 6)), M((MACRO_NUM + 7)), M((MACRO_NUM + 8)), M((MACRO_NUM + 9)), M((MACRO_NUM + 0)), _______, ______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_SLSH, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, ______, _______, _______, _______, _______, _______, _______),

    [_QM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, //16 keys
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, // 16 keys
        ________, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         // 15 keys
        __________, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _____________, _______,          // 14 keys
        _______, ________, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, __________, ______, _______,       // 15 keys
        _______, _______, _______, KC_BTN1, XXXXXXX, KC_BTN1, _______, _______, _______, _______, ______, _______),                                     // 10 keys

    [_NUMKEYS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, //16 keys
        _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, _______, _______, _______,                               //16 keys
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          // 15 keys
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   // 14 keys
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          // 15 keys
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                                      // 12 keys
        ),
    [_ML] = LAYOUT(
        RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, KC_P0, KC_PMNS, KC_PPLS, __________, _______, _______,
        ________, _______, _______, _______, RESET, _______, _______, KC_P4, KC_P5, KC_P6, _______, _______, _______, _______, BL_TOGG,        // 15 keys
        __________, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, _______, _______, KC_PENT, BL_INC,              // 14 keys
        _______, _______, _______, KC_PAST, KC_CALC, _______, _______, _______, KC_NLCK, KC_P0, KC_PDOT, KC_PSLS, __________, KC_VOLU, BL_DEC, // 14 keys
        _______, _______, TG(_QM), KC_MPLY, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT                             // 10 keys
        )

};

/*
[_ML] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______, _______, _______, _______, _______, _______, _______, KC_P7 , KC_P8  , KC_P9  , KC_P0, KC_PMNS, KC_PPLS, __________ , _______, KC_MUTE , 
  ________  , _______, _______, _______, _______, _______, _______, KC_P4  , KC_P5  , KC_P6 , _______, _______, _______, _______  , BL_TOGG,  // 15 keys
  __________   , _______, _______, _______, _______, _______, _______, KC_P1 , KC_P2  , KC_P3  , _______, _______, KC_PENT        , BL_INC ,  // 14 keys
  _______,   , _______, KC_PAST, KC_CALC, _______, _______, _______, KC_NLCK, KC_P0, KC_PDOT, KC_PSLS,  __________, KC_VOLU  , BL_DEC ,   // 14 keys
  _______, _______  , TG(_QM),                 KC_MPLY,  _______,  _______,          _______, _______, _______, KC_MPRV, KC_VOLD  , KC_MNXT  // 10 keys
  )


_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,
_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
_______,  _______,  _______,  _______,  _______,   _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
_______,  _______,  _______,                      _______   ,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
*/
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRB |= (1 << 2); PORTB &= ~(1 << 2);
    } else {
        DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
    }
}
bool magicThumb1Pressed = false;
bool magicThumb2Pressed = false;


bool leftshiftPressed = false;
bool leftCtrlPressed = false;
bool rightCtrlPressed = false;
bool rightshiftPressed = false;
bool spacePressed = false;
bool numLayerActive = false;
int keysSinceNumLayer = 0;

void PrintInt(int a)
{
  char buf[2] = "?";
  buf[0] = '0' + a;
  send_string(buf);
}

void DebugThumbState(void)
{
  PrintInt(rightshiftPressed);
  PrintInt(spacePressed);
  PrintInt(numLayerActive);
  PrintInt(keysSinceNumLayer);
  PrintInt(magicThumb1Pressed);
  PrintInt(magicThumb2Pressed);
  send_string("-");
}
int count = 0;

void EmitCursorsFromNumber(int numKey)
{
  int keycode;
  if (numKey == 6)
  {
    keycode = KC_LEFT;
  }
  else if (numKey == 7)
  {
    keycode = KC_DOWN;
  }
  else if (numKey == 8)
  {
    keycode = KC_UP;
  }
  else if (numKey == 9)
  {
    keycode = KC_RIGHT;
  }
  else
  {
    return;
  }
  for (int i = 0; i < 8;i++)
  {
    register_code(keycode);
    unregister_code(keycode);
  }
}




const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {

    // for basic strings
    case MACRO_PIPE: {
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT("\\")); 
            return false;
        }
    }

   case MACRO_TILDE: {
       if (record->event.pressed) {
           SEND_STRING(SS_LSFT("`")); 
           return false;  
       }
   }

   case MACRO_LESS_THAN: {
       if (record->event.pressed) {
           SEND_STRING(SS_LSFT("<")); 
           return false;  
       }
   }
   case MACRO_GREATER_THAN: {
       if (record->event.pressed) {
           SEND_STRING(SS_LSFT(">")); 
           return false;  
       }
   }

   case MACRO_QUESTION: {
       if (record->event.pressed) {
           SEND_STRING(SS_LSFT("/")); //'?'
           return false;
       }
     }
   case MACRO_SHINS: {
    if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_RSHIFT));
        register_code(KC_INSERT);
        unregister_code(KC_INSERT);
        SEND_STRING(SS_UP(X_RSHIFT));
        return false;
    }
   }

  }
  if (record->event.pressed) {
    if (id >= MACRO_NUM && id < MACRO_NUM +10)
    {
      int numKey = id - MACRO_NUM;
      if (IS_LAYER_ON(_FL))
      {
        EmitCursorsFromNumber(numKey);
      }
      else
      {
        if (rightCtrlPressed)
        {
          if (numKey == 8)
          {
              SEND_STRING(SS_UP(X_RCTRL));
              SEND_STRING("[");
              SEND_STRING(SS_DOWN(X_RCTRL));
          }
          else if (numKey == 9)
          {
              SEND_STRING(SS_UP(X_RCTRL));
              SEND_STRING("]");
              SEND_STRING(SS_DOWN(X_RCTRL));
          }
        }
        else
        {
          send_char('0'+numKey);
        }
      }
      return false;
    }
    else if (id >= MACRO_SHNUM && id < MACRO_SHNUM +10)
    {

        int numKey = id - MACRO_SHNUM;
        char toSend[]="0";

        toSend[0]+=numKey;

     /*   if (rightCtrlPressed)
        {
          if (numKey == 9)
          {
            toSend[0]='{';
          }
          else if(numKey==0)
          {
            toSend[0]='}';
          }
          SEND_STRING(SS_UP(X_RCTRL));
          send_string(toSend);
          SEND_STRING(SS_DOWN(X_RCTRL));
        }
        else*/
        {
          SEND_STRING(SS_DOWN(X_RSHIFT));
          send_string(toSend);
          SEND_STRING(SS_UP(X_RSHIFT));
        }
        return false;
    }
  }
  return MACRO_NONE;
};


void DS(void)
{
  SEND_STRING("DS");
  if (leftshiftPressed)
  {
    SEND_STRING("Z");
  }
  if (leftCtrlPressed)
  {
    SEND_STRING("X");
  }
} 
void UpdateThumbButtons(void)
{
  
  //DebugThumbState();

  bool newSpacePressed = magicThumb1Pressed && !magicThumb2Pressed;
  bool newRightShiftPressed = magicThumb2Pressed && !magicThumb1Pressed;
  bool newNumLayer = magicThumb2Pressed && magicThumb1Pressed;

  int oldSpacePressed = spacePressed;

  if (newSpacePressed && !spacePressed && 
       !(numLayerActive))  //dont emit space if transitioning out of numLayer and we actually typed a number
  {
    spacePressed = true;
    register_code(KC_SPC);
  }
  if (!newSpacePressed && spacePressed)
  {
    spacePressed = false;
    unregister_code(KC_SPC);
  }

  if (newRightShiftPressed && !rightshiftPressed)
  {
    register_code(KC_RSFT);
  }
  else if (!newRightShiftPressed && rightshiftPressed)
  {
    unregister_code(KC_RSFT);
  }
  rightshiftPressed = newRightShiftPressed;

  if (newNumLayer && !numLayerActive)
  {
    layer_on(_NUM);
    // if space was already down count as having sent a key so we don't send another
    keysSinceNumLayer = oldSpacePressed?1:0;
  }
  else if (!newNumLayer && numLayerActive)
  {
    layer_off(_NUM);
    if(keysSinceNumLayer==0)
    {
      send_string(" ");
    }
  }          
  numLayerActive = newNumLayer;
}
void SendLeftCapKey(int key)
{
  switch(key)
  {
    case KC_Q: SEND_STRING(SS_TAP(X_Q)); break;
    case KC_W: SEND_STRING(SS_TAP(X_W)); break;
    case KC_E: SEND_STRING(SS_TAP(X_E)); break;
    case KC_R: SEND_STRING(SS_TAP(X_R)); break;
    case KC_T: SEND_STRING(SS_TAP(X_T)); break;
    case KC_A: SEND_STRING(SS_TAP(X_A)); break;
    case KC_S: SEND_STRING(SS_TAP(X_S)); break;
    case KC_D: SEND_STRING(SS_TAP(X_D)); break;
    case KC_F: SEND_STRING(SS_TAP(X_F)); break;
    case KC_G: SEND_STRING(SS_TAP(X_G)); break;
    case KC_Z: SEND_STRING(SS_TAP(X_Z)); break;
    case KC_X: SEND_STRING(SS_TAP(X_X)); break;
    case KC_C: SEND_STRING(SS_TAP(X_C)); break;
    case KC_V: SEND_STRING(SS_TAP(X_V)); break;
    case KC_B: SEND_STRING(SS_TAP(X_B)); break;
    case KC_1: SEND_STRING(SS_TAP(X_1)); break;
    case KC_2: SEND_STRING(SS_TAP(X_2)); break;
    case KC_3: SEND_STRING(SS_TAP(X_3)); break;
    case KC_4: SEND_STRING(SS_TAP(X_4)); break;
    case KC_5: SEND_STRING(SS_TAP(X_5)); break;

  }
}

bool LeftShiftPlusKey(uint16_t keycode)
{
  switch (keycode)
  {
  case KC_F9:
    SEND_STRING("9");
    return false;
  case KC_F10:
    SEND_STRING("0");
    return false;
  case KC_I:
    SEND_STRING(SS_UP(X_LSHIFT));
    SEND_STRING("{");
    SEND_STRING(SS_DOWN(X_LSHIFT));
    return false;
  case KC_O:
    SEND_STRING(SS_UP(X_LSHIFT));
    SEND_STRING("}");
    SEND_STRING(SS_DOWN(X_LSHIFT));
    return false;
  case KC_K:
    SEND_STRING(SS_UP(X_LSHIFT));
    SEND_STRING("[");
    SEND_STRING(SS_DOWN(X_LSHIFT));
    return false;
  case KC_L:
    SEND_STRING(SS_UP(X_LSHIFT));
    SEND_STRING("]");
    SEND_STRING(SS_DOWN(X_LSHIFT));
    return false;
  case MAGIC_SCOLON:
    SEND_STRING(";");
    return false;
  }
  
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (record->event.pressed)
  {
    keysSinceNumLayer ++;
  }

  if (leftshiftPressed && record->event.pressed)
  {
    return LeftShiftPlusKey(keycode);
  }

  switch (keycode) {
    case KC_LSFT:
      
     
      if (record->event.pressed) {
        leftshiftPressed = true;
        // Do something when pressed
      } else {
        leftshiftPressed = false;
        // Do something else when release
      }
      return true; 

    case KC_RSFT:
      if (record->event.pressed) {
        rightshiftPressed = true;
        // Do something when pressed
      } else {
        rightshiftPressed = false;
        // Do something else when release
      }
      return true; 

    case KC_LCTL:
      if (record->event.pressed) {
        leftCtrlPressed = true;
        // Do something when pressed
      } else {
        leftCtrlPressed = false;
        // Do something else when release
      }
      return true;
    //case CONTROL_OR_SHIFT:
      //controlOrShiftKeyPressed = record->event.pressed;
      //bool numLayerActive = IS_LAYER_ON(_NUM);
      //bool newRightCtrlPressed = controlOrShiftKeyPressed && !numLayerActive;
      //bool newRightShiftPressed = controlOrShiftKeyPressed && numLayerActive;

      case KC_RCTL:
      if (record->event.pressed) {
        rightCtrlPressed = true;
        // Do something when pressed
      } else {
        rightCtrlPressed = false;
        // Do something else when release
      }
      return true;

      

      case KC_QUOT:
          if(rightshiftPressed && record->event.pressed)
          {
            SEND_STRING("-"); //will become _
            return false;
          }
          else
          {
            return true;
          }

      case MAGIC_THUMB1:
        magicThumb1Pressed = record->event.pressed;
        UpdateThumbButtons();
        return false;
      case MAGIC_THUMB2:
        magicThumb2Pressed = record->event.pressed;
        UpdateThumbButtons();
        return false;


      case MAGIC_SCOLON:
            if (record->event.pressed)
            {
              layer_on(_SL);
            }
            else
            {
                layer_off(_SL);
            }
            return false; 
    default:
      if (record->event.pressed)
      {
        if (keycode > SHIFT_LEFT_KEYS)
        {
          SEND_STRING(SS_DOWN(X_RSHIFT));
          SendLeftCapKey(keycode - SHIFT_LEFT_KEYS);
          //SEND_STRING("\1\x1a");
          //SEND_STRING(SS_TAP(keycode-SHIFT_LEFT_KEYS));
          SEND_STRING(SS_UP(X_RSHIFT));
        }
      }

      return true; // Process all other keycodes normally
  }
}