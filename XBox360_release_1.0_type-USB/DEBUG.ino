void DEBUG()
{
  buttTick();
  Serial.print("HOME:");
  Serial.print(butt.state());

  Serial.print("\tBACK:");
  Serial.print(butt2.state());

  Serial.print("\tSTART:");
  Serial.print(butt3.state());

  Serial.print("\tA:");
  Serial.print(butt4.state());

  Serial.print("\tB:");
  Serial.print(butt5.state());

  buttTick();

  Serial.print("\tY:");
  Serial.print(butt6.state());

  Serial.print("\tX:");
  Serial.print(butt7.state());

  Serial.print("\tUP:");
  Serial.print(butt8.state());

  Serial.print("\tLEFT:");
  Serial.print(butt9.state());

  Serial.print("\tDOWN:");
  Serial.print(butt10.state());

  buttTick();

  Serial.print("\tRIGHT:");
  Serial.print(butt11.state());

  Serial.print("\tRS:");
  Serial.print(butt12.state());

  Serial.print("\tLS:");
  Serial.print(butt13.state());

  Serial.print("\tBR:");
  Serial.print(butt14.state());

  Serial.print("\tBL:");
  Serial.println(butt15.state());

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

  if (MD == 0)
  {
    Serial.print("XLS:");
    Serial.print(XL);
    Serial.print("\tYLS:");
    Serial.print(YL);


    Serial.print("\tXRS:");
    Serial.print(XR);
    Serial.print("\tYRS:");
    Serial.print(YR);

    Serial.print("\tLT:");
    Serial.print(TRPL);
    Serial.print("\tRT:");
    Serial.println(TRPR);
  }
  else
  {
    Serial.print("XLS:");
    Serial.print(PXML);
    Serial.print("\tYLS:");
    Serial.print(PYML);


    Serial.print("\tXRS:");
    Serial.print(PTXR);
    Serial.print("\tYRS:");
    Serial.print(PTYR);

    Serial.print("\tLT:");
    Serial.print(PMTL);
    Serial.print("\tRT:");
    Serial.println(PMTR);
  }
  delay(50);
}
