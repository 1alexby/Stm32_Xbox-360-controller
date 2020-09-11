/*
 * =================== XBOX 360 КОНТРОЛЛЕР НА STM32 ================
 * Версия X360Rele_1.0
 * Для того чтобы не было ошибок, необходимо обновить библиотеку USBComposite
 * ----- Ссылка на GitHub ----------
 * https://github.com/arpruss/USBComposite_stm32f1
 * 
 * Если вы впервые использкете платформу stm32f1 или прошиваете его через ардуино иде.
 * Советую к ознокомлению:
 * https://habr.com/ru/post/395577/
 * https://eax.me/stm32-arduino-ide/
 * https://www.youtube.com/watch?v=5mThFmpC1U4
 * https://www.youtube.com/watch?v=878k4KqF7Xs
 * 
 * 
 * Геймпад пока что не работает с XBOX'ом. В процессе.
 * Геймпад выполнен в виде Xbox One controller
 * 
 * ------- О индикации ----------
 *  1. Светодиод ммигает - Контроллер не инициализировался на пк или подключения к пк нет
 *  2. Светодиод горит белым - Контроллер подключен к пк и готов работать
 *  3. Светодиод переодически мигает - Контроллер теряет связь с пк, проблема чаще связанна с соединением кабеля с пк
 *  4. Светодиод горит крассным - контроллер находиться в Debug режиме
 *  
 *  Известные проблемы:
 *  ? У контроллера перестал гореть светодиод но он работает
 *  ! Скорее всего проблема связана с просадкой напряжения, помогает замена вибромоторов или хорошая фильтрация по питанию 3.3 вольта
 *  
 *  ? Провод в порядке но геймпад переодически отваливаеться
 *  ! Связанно это скорее всего из за высокого потребления в сети
 *  
 *  Это пока что все известные проблемы
 *  Не рекомендую прошивать через STM32duino Bootloader - возникали проблемы при подключении к некоторым устройствам
 * 
 */
//===========================
//======== НАСТРОЙКИ ========
//===========================

//======= кнопки ============
#define PIN1  PB4 //Home
#define PIN2  PB3 //Back
#define PIN3  PB5 //Start
#define PIN4  PA8 //A
#define PIN5  PB15 //B
#define PIN6  PB14 //Y
#define PIN7  PB13 //X
#define PIN8  PB1 //UP
#define PIN9  PA6 //Left
#define PIN10 PA7 //Down
#define PIN11 PB0 //Right
#define PIN12 PB9 //RS
#define PIN13 PB10 //LS
#define PIN14 PB12 //BR
#define PIN15 PB11 //BL
//======== Аналоги ==========
#define PINA1 PA5 //LT
#define PINA2 PA2 //RT
#define PINA3 PA4 //LY
#define PINA4 PA3 //LX
#define PINA5 PA0 //RY
#define PINA6 PA1 //RX
//======= вибромоторы =======
#define VibroLeft PB6
#define VibroRight PB7
#define VibroMode 2 // 1 - работа только на левом двигателе; 2 - работа на обоих двигателях
//========== программная кнопка =========
#define PIN_Prog_1 PB8 // программная кнопка (пока не используеться)
//========== настройка светодиода =========
#define ColorType GRB //если светодиод свитися не правильно, меняем параметры
#define LedPin PC15  //пин сетодиода
#define LedType WS2812B //тип светодиода
#define NUM_LEDS 1 //количество светодиодов (не меняем)

#define DEBUG_MODE 0 //отпраляет данные контроллера в ком порт (1 - дебаг, 0 - обычный режим)
#define MD 0  // режим отправки данных 

#define Type_Triger_Read 1 //тип чтения данных с тригиров: 0 - чтение данных с тригира после включением (автоматический); 1 - использует заранее записанное значение(ручной)
//==== для ручной настройки тригиров ======
#define Triger_Data_Left  650  // настройка нулевого положения тригиров
#define Triger_Data_Right 650  


#define parametresDebounce 30
#define parametresTimeout 10
#define parametresClickTimeout 10
#define parametresStepTimeout 10
// =======библиотеки========
#include <USBComposite.h>
#include "GyverButton.h"
#include <FastLED.h>

GButton butt(PIN1);
GButton butt2(PIN2);
GButton butt3(PIN3);
GButton butt4(PIN4);
GButton butt5(PIN5);
GButton butt6(PIN6);
GButton butt7(PIN7);
GButton butt8(PIN8);
GButton butt9(PIN9);
GButton butt10(PIN10);
GButton butt11(PIN11);
GButton butt12(PIN12);
GButton butt13(PIN13);
GButton butt14(PIN14);
GButton butt15(PIN15);
GButton progButt(PIN_Prog_1);

CRGB leds[NUM_LEDS];

USBXBox360 XBox360;

USBHID HID;
HIDJoystick Joystick(HID);
HIDKeyboard Keyboard(HID);

#define NORM NORM_OPEN
#define PULL HIGH_PULL
bool checkButt[15];
float CPTRL, CPTRR;
byte modes;
void setup() {
  ButtInit();
  PinInit();
  buttTick();
  FastLED.addLeds<WS2812B, LedPin, ColorType>(leds, NUM_LEDS);
  if (Type_Triger_Read == 0)
  {
    delay(10);
    analogRead(PINA1);
    analogRead(PINA2);
    CPTRL = analogRead(PINA1);
    CPTRR = analogRead(PINA2);
  }
  if (Type_Triger_Read == 1)
  {
    CPTRL = Triger_Data_Left;
    CPTRR = Triger_Data_Right;
  }

  if (!DEBUG_MODE)
  {
    FastLED.show();
    FastLED.clear();
    modes = 1;
    
    if (modes == 1)
      {
        XBox360.begin();
      }
    ledON();

  }  else {
    Serial.begin(9600);
    leds[0] = CHSV(0, 255, 50);
    FastLED.show();
    modes = 5;
  }
  
  delay(200);
  USBwire(); // проверка состояния в USB
  progButt.setTimeout(800);
  buttTick();
}

void USBwire()
{
  while (!USBComposite)
  {
    WaitConection();
  }
}

void loop()
{
  buttTick();
  if (!USBComposite)
  {
    USBwire();
  }

  XBox360.setRumbleCallback(&Vibro); // проверяем данные о вибрации
  XBox360.setLEDCallback(&LEDCALL);  // проверяем состояние (не используеться)

  if (modes == 1)
  {
    XboxModeJoy();
  }
  if (modes == 2)
  {
    KeyModeJoy();
  }
  if (modes == 3)
  {
    JoyMode();
  }
  if (modes == 5)
  {
    DEBUG();
  }
}

void Vibro(uint8_t left, uint8_t right)
{
  if(VibroMode == 1)
  {
    analogWrite(VibroLeft, left); 
  } else if (VibroMode == 2)
  {
    analogWrite(VibroLeft, left);
    analogWrite(VibroRight, right);
  }
  
}
void LEDCALL(uint8_t A)
{
 // Serial.print("LED_Callback: ");
 // Serial.println(A);
}
