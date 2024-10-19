#define LAG(kc) (QK_LALT | QK_LGUI | (kc))

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
    SEND_STRING("9");  // (
    return false;
  case KC_F10:
    SEND_STRING("0");  // ) 
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
    SEND_STRING(";");  // becomes :
    return false;
  case KC_SEND_SPECIAL_STR_1:
    SEND_STRING("A");
    return false;
  case KC_SEND_SPECIAL_STR_2:
    SEND_STRING("B");
    return false;
  case KC_SEND_SPECIAL_STR_3:
    SEND_STRING("C");
    return false;
  case KC_SEND_SPECIAL_STR_4:
    SEND_STRING("D");
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