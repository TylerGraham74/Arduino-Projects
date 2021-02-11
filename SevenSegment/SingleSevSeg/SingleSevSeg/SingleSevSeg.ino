void setup()
{
  // define pin modes

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 12; i++)
  {
    num(i);
    delay(600);
    clearIt();
  }
  /*for(int i = 0; i < 10; i++)
    {
    digitalWrite(i, HIGH);
    delay(600);
    }
    for(int i = 0; i < 10; i++)
    {
    digitalWrite(i, LOW);
    delay(600);
    }
    delay(1000);
  */
}

void num(int num) //10 for decimal
{
  if (num == 0)
    zero();
  else if (num == 1)
    one();
  else if (num == 2)
    two();
  else if (num == 3)
    three();
  else if (num == 4)
    four();
  else if (num == 5)
    five();
  else if (num == 6)
    six();
  else if (num == 7)
    seven();
  else if (num == 8)
    eight();
  else if (num == 9)
    nine();
  else if (num == 10)
    dec();
  else
    clearIt();
}
void zero()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  }
}

void one()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(5, HIGH);
  }
}


void two()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
  }
}


void three()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
  }
}

void four()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}

void five()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}

void six()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}

void seven()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
  }
}

void eight()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}

void nine()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}

void dec()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(9, HIGH);
  }
}

void H()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}


void E()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}

void Y()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}

void A()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}

void L()
{
  for (int i = 0; i < 1; i++)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
  }
}

void clearIt()
{
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(i, LOW);
  }
}
