void XboxModeJoy()
{
  butt.tick();
  if (checkButt[0] != butt.state())
  {
    if (butt.state())
    {
      for (int i = 50; i <= 100; i++)
      {
        leds[0] = CHSV(45, 0, i);
        FastLED.show();
        delay(2);
      }
    }
    
    XBox360.button(11, butt.state()); //HOME  11
    
    if (!butt.state())
    {
      delay(50);
      for (int i = 100; i >= 55; i--)
      {
        leds[0] = CHSV(45, 0, i);
        FastLED.show();
        delay(10);
      }
    }
    checkButt[0] = butt.state();
  }

  butt2.tick();
  if (checkButt[1] != butt2.state())
  {
    XBox360.button(6, butt2.state()); // BACK
    checkButt[1] = butt2.state();
  }

  butt3.tick();
  if (checkButt[2] != butt3.state())
  {
    XBox360.button(5, butt3.state()); // START
    checkButt[2] = butt3.state();
  }

  butt4.tick();
  if (checkButt[3] != butt4.state())
  {
    XBox360.button(13, butt4.state()); //A
    checkButt[3] = butt4.state();
  }

  butt5.tick();
  if (checkButt[4] != butt5.state())
  {
    XBox360.button(14, butt5.state()); //B
    checkButt[4] = butt5.state();
  }

  butt6.tick();
  if (checkButt[5] != butt6.state())
  {
    XBox360.button(16, butt6.state()); //Y
    checkButt[5] = butt6.state();
  }

  butt7.tick();
  if (checkButt[6] != butt7.state())
  {
    XBox360.button(15, butt7.state()); //X
    checkButt[6] = butt7.state();
  }

  butt8.tick();
  if (checkButt[7] != butt8.state())
  {
    XBox360.button(1, butt8.state()); //UP
    checkButt[7] = butt8.state();
  }

  butt9.tick();
  if (checkButt[8] != butt9.state())
  {
    XBox360.button(3, butt9.state()); //LEFT
    checkButt[8] = butt9.state();
  }

  butt10.tick();
  if (checkButt[9] != butt10.state())
  {
    XBox360.button(2, butt10.state()); //DOWN
    checkButt[9] = butt10.state();
  }

  butt11.tick();
  if (checkButt[10] != butt11.state())
  {
    XBox360.button(4, butt11.state()); //RIGHT
    checkButt[10] = butt11.state();
  }

  butt12.tick();
  if (checkButt[11] != butt12.state())
  {
    XBox360.button(8, butt12.state()); //RS
    checkButt[11] = butt12.state();
  }

  butt13.tick();
  if (checkButt[12] != butt13.state())
  {
    XBox360.button(7, butt13.state()); //LS
    checkButt[12] = butt13.state();
  }

  butt14.tick();
  if (checkButt[13] != butt14.state())
  {
    XBox360.button(10, butt14.state()); //BR
    checkButt[13] = butt14.state();
  }

  butt15.tick();
  if (checkButt[14] != butt15.state())
  {
    XBox360.button(9, butt15.state()); //BL
    checkButt[14] = butt15.state();
  }
  int v = 32767;
  float PXML = analogRead(PINA4);
  float XLS = PXML / 2048 - 1;
  int XL = XLS * v;

  float PYML = analogRead(PINA3);
  float YLS = PYML / 2048 - 1;
  int YL = YLS * v;

  int PMTL = analogRead(PINA1);
  float TRLS = PMTL / CPTRL - 1;
  int TRPL = TRLS * 58;
  TRPL = abs(TRPL);

  //----------------------------------------------------
  float PTXR = analogRead(PINA6) + 1;
  float XRS = PTXR / 2048 - 1;
  int XR = XRS * v;

  float PTYR = analogRead(PINA5) + 1;
  float YRS = PTYR / 2048 - 1;
  int YR = YRS * v;

  float PMTR = analogRead(PINA2) + 190;
  float TRRS = PMTR / CPTRR - 1;
  int TRPR = TRRS * 59;
  TRPR = abs(TRPR);

  if (TRPR < 55)
  {
    TRPR = 0;
  }
  if (TRPL < 55)
  {
    TRPL = 0;
  }
  if (TRPL >= 255)
  {
    TRPL = 255;
  }
  if (TRPR >= 255)
  {
    TRPR = 255;
  }

#define call 6144

  XL = -XL;
  XR = -XR;

  if (XL < 15000 && XL > -call)
  {
    XL = 0;
  }
  if (YL < 9500 && YL > -call)
  {
    YL = 0;
  }

  if (XR < call && XR > -call)
  {
    XR = 0;
  }
  if (YR < call && YR > -call)
  {
    YR = 0;
  }

  XBox360.X(XL);
  XBox360.Y(YL);

  XBox360.XRight(XR);
  XBox360.YRight(YR);

  XBox360.sliderRight(TRPR);
  XBox360.sliderLeft(TRPL);
}
