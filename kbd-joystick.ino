// KBD-JOYSTICK
//キーボードとして認識するジョイスティック
// (C)2024 takuya matsubara
//
#include "Keyboard.h"

#define BUTTON_MAX 12
int button_old[BUTTON_MAX];
int gpio_table[BUTTON_MAX]={
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11
};
char key_table[BUTTON_MAX]={
  KEY_KP_8,
  KEY_KP_2,
  KEY_KP_4,
  KEY_KP_6,
  'z',
  'x',
  'c',
  KEY_ESC,
  KEY_LEFT_SHIFT,
  KEY_LEFT_ALT,
  ' ',
  KEY_KP_ENTER
};

void setup() {
  int i;
  for(i=0; i<BUTTON_MAX; i++){
    pinMode(gpio_table[i], INPUT_PULLUP);
    button_old[i] = 1;
  }
  Keyboard.begin();
}

void loop() {
  int i,button_now;
  for(i=0; i<BUTTON_MAX; i++){
    button_now = digitalRead(gpio_table[i]);
    if(button_now != button_old[i]){
      button_old[i] = button_now;
      if(button_now == 0){
        Keyboard.press(key_table[i]);
      }else{
        Keyboard.release(key_table[i]);
      }
    }
  }
  delay(16);
}
