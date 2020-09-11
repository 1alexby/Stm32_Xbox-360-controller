void ledON()
{
  if (modes == 1)
  {
    for (int i = 0; i <= 50; i++)
    {
      leds[0] = CHSV(0, 0, i);
      FastLED.show();
      delay(3);
    }
  }
  if (modes == 3)
  {
    for (int i = 0; i <= 50; i++)
    {
      leds[0] = CHSV(85, 255, i);
      FastLED.show();
      delay(3);
    }
  }
  if (modes == 2)
  {
    for (int i = 0; i <= 50; i++)
    {
      leds[0] = CHSV(170, 255, i);
      FastLED.show();
      delay(3);
    }
  }
}

void WaitConection()
{
  if (modes == 1)
  {
    leds[0] = CHSV(40, 0, 0);
    FastLED.show();
    delay(200);
    leds[0] = CHSV(40, 0, 50);
    FastLED.show();
    delay(200);
  }
  if (modes == 3)
  {
    leds[0] = CHSV(85, 255, 0);
    FastLED.show();
    delay(200);
    leds[0] = CHSV(85, 255, 50);
    FastLED.show();
    delay(200);
  }
  if (modes == 2)
  {
    leds[0] = CHSV(170, 255, 0);
    FastLED.show();
    delay(200);
    leds[0] = CHSV(170, 255, 50);
    FastLED.show();
    delay(200);
  }
}


void ButtInit()
{
  butt.setType(PULL);
  butt.setDirection(NORM);

  butt2.setType(PULL);
  butt2.setDirection(NORM);

  butt3.setType(PULL);
  butt3.setDirection(NORM);

  butt4.setType(PULL);
  butt4.setDirection(NORM);

  butt5.setType(PULL);
  butt5.setDirection(NORM);

  butt6.setType(PULL);
  butt6.setDirection(NORM);

  butt7.setType(PULL);
  butt7.setDirection(NORM);

  butt8.setType(PULL);
  butt8.setDirection(NORM);

  butt9.setType(PULL);
  butt9.setDirection(NORM);

  butt10.setType(PULL);
  butt10.setDirection(NORM);

  butt11.setType(PULL);
  butt11.setDirection(NORM);

  butt12.setType(PULL);
  butt12.setDirection(NORM);

  butt13.setType(PULL);
  butt13.setDirection(NORM);

  butt14.setType(PULL);
  butt14.setDirection(NORM);

  butt15.setType(PULL);
  butt15.setDirection(NORM);

  progButt.setType(PULL);
  progButt.setDirection(NORM);

  butt.setDebounce(parametresDebounce);
  butt.setTimeout(parametresTimeout);
  butt.setClickTimeout(parametresClickTimeout);
  butt.setStepTimeout(parametresStepTimeout);

  butt2.setDebounce(parametresDebounce);
  butt2.setTimeout(parametresTimeout);
  butt2.setClickTimeout(parametresClickTimeout);
  butt2.setStepTimeout(parametresStepTimeout);

  butt3.setDebounce(parametresDebounce);
  butt3.setTimeout(parametresTimeout);
  butt3.setClickTimeout(parametresClickTimeout);
  butt3.setStepTimeout(parametresStepTimeout);

  butt4.setDebounce(parametresDebounce);
  butt4.setTimeout(parametresTimeout);
  butt4.setClickTimeout(parametresClickTimeout);
  butt4.setStepTimeout(parametresStepTimeout);

  butt5.setDebounce(parametresDebounce);
  butt5.setTimeout(parametresTimeout);
  butt5.setClickTimeout(parametresClickTimeout);
  butt5.setStepTimeout(parametresStepTimeout);

  butt6.setDebounce(parametresDebounce);
  butt6.setTimeout(parametresTimeout);
  butt6.setClickTimeout(parametresClickTimeout);
  butt6.setStepTimeout(parametresStepTimeout);

  butt7.setDebounce(parametresDebounce);
  butt7.setTimeout(parametresTimeout);
  butt7.setClickTimeout(parametresClickTimeout);
  butt7.setStepTimeout(parametresStepTimeout);

  butt8.setDebounce(parametresDebounce);
  butt8.setTimeout(parametresTimeout);
  butt8.setClickTimeout(parametresClickTimeout);
  butt8.setStepTimeout(parametresStepTimeout);

  butt9.setDebounce(parametresDebounce);
  butt9.setTimeout(parametresTimeout);
  butt9.setClickTimeout(parametresClickTimeout);
  butt9.setStepTimeout(parametresStepTimeout);

  butt10.setDebounce(parametresDebounce);
  butt10.setTimeout(parametresTimeout);
  butt10.setClickTimeout(parametresClickTimeout);
  butt10.setStepTimeout(parametresStepTimeout);

  butt11.setDebounce(parametresDebounce);
  butt11.setTimeout(parametresTimeout);
  butt11.setClickTimeout(parametresClickTimeout);
  butt11.setStepTimeout(parametresStepTimeout);

  butt12.setDebounce(parametresDebounce);
  butt12.setTimeout(parametresTimeout);
  butt12.setClickTimeout(parametresClickTimeout);
  butt12.setStepTimeout(parametresStepTimeout);

  butt13.setDebounce(parametresDebounce);
  butt13.setTimeout(parametresTimeout);
  butt13.setClickTimeout(parametresClickTimeout);
  butt13.setStepTimeout(parametresStepTimeout);

  butt14.setDebounce(parametresDebounce);
  butt14.setTimeout(parametresTimeout);
  butt14.setClickTimeout(parametresClickTimeout);
  butt14.setStepTimeout(parametresStepTimeout);

  butt15.setDebounce(parametresDebounce);
  butt15.setTimeout(parametresTimeout);
  butt15.setClickTimeout(parametresClickTimeout);
  butt15.setStepTimeout(parametresStepTimeout);

}

void PinInit()
{
  pinMode(PINA1, INPUT);
  pinMode(PINA2, INPUT);
  pinMode(PINA3, INPUT);
  pinMode(PINA4, INPUT);
  pinMode(PINA5, INPUT);
  pinMode(PINA6, INPUT);
}
void buttTick()
{
  butt.tick();
  butt2.tick();
  butt3.tick();
  butt4.tick();
  butt5.tick();
  butt6.tick();
  butt7.tick();
  butt8.tick();
  butt9.tick();
  butt10.tick();
  butt11.tick();
  butt12.tick();
  butt13.tick();
  butt14.tick();
  butt15.tick();
  progButt.tick();
}

int reverse(int i, int r)
{
  i = r - i;
  return i;
}
