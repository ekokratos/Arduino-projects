int en1 = 10;
int en2 = 11; //enable pins

const int m1a = 6; //left motors
const int m1b = 7;

const int m2a = 9; //right motors
const int m2b = 8;

const int LED = 13; //Using built-in LED pin

//Initializing 5 LDRs to analog pins
int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
int ldr4 = A3;
int ldr5 = A4;

int threshold = 400;

void rotate_right()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  Serial.print("right");
}

void  rotate_left()
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
  Serial.print("left");
}

void SetSpeed(int s)
{
  analogWrite(en1, s);
  analogWrite(en2, s);
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);

  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);

  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  pinMode(ldr4, INPUT);
  pinMode(ldr5, INPUT);

  Serial.begin(9600);

}

void loop()
{
  //LDR positions mentioned in LDR_position.jpg
  int value1 = analogRead(ldr5);  //1
  int value2 = analogRead(ldr4);  //2
  int value3 = analogRead(ldr3);  //3
  int value4 = analogRead(ldr2);  //4
  int value5 = analogRead(ldr1);  //5

  Serial.print(value1); Serial.print("\t");
  Serial.print(value2); Serial.print("\t");
  Serial.print(value3); Serial.print("\t");
  Serial.print(value4); Serial.print("\t");
  Serial.print(value5); Serial.print("\t");


  if (value5 > threshold && value1 > threshold) // light detected by LDR 1,5 detected
  {
    SetSpeed(200);
    rotate_left();
    digitalWrite(LED, LOW);
  }
  else if (value5 > threshold)  // light detected by LDR 5 detected
  {
    SetSpeed(200);
    rotate_left();
    digitalWrite(LED, LOW);
  }
  else if (value5 > threshold && value4 > threshold) // LDR 4,5 detected
  {
    SetSpeed(200);
    rotate_left();
    digitalWrite(LED, LOW);
  }
  else if (value4 > threshold) // LDR 4,5 detected
  {
    SetSpeed(200);
    rotate_left();
    digitalWrite(LED, LOW);
  }
  else if (value1 > threshold && value2 > threshold) // LDR 1,2 detected
  {
    SetSpeed(200);
    rotate_right();
    digitalWrite(LED, LOW);
  }
  else if (value2 > threshold && value3 > threshold) // LDR 2,3 detected
  { SetSpeed(200);
    rotate_right();
    digitalWrite(LED, LOW);
  }
  else if (value2 > threshold) // LDR 2 detected
  {
    SetSpeed(200);
    rotate_right();
    digitalWrite(LED, LOW);
  }

  else if (value3 > threshold)
  {
    SetSpeed(200);
    rotate_right();
    digitalWrite(LED, LOW);
  }
  else if (value4 > threshold && value3 > threshold)
  {
    SetSpeed(200);
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
    Serial.println("Backward");
    digitalWrite(LED, LOW);
  }

  else if (value1 > threshold )
  {
    SetSpeed(200);
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    Serial.println("Forward");
    digitalWrite(LED, LOW);
  }
  else          // no light detected
  {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    Serial.println("Stop");
    digitalWrite(LED, HIGH);
  }

  Serial.println();
}

