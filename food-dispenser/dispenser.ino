// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
#include <Servo.h>

Servo servo;

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {

  servo.attach(9);
  servo.write(0);

  Serial.begin(9600);

  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop () {
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  if ((now.hour() == 15) && (now.minute(02) == ) && (now.second() == 10) )
  {
    Serial.println("ALARM 1 TRIGGERED!");
    servo.write(90);
    delay(1500);
    servo.write(0);
  }

  if ((now.hour() == 14) && (now.minute() == 50) && (now.second() == 10))
  {
    Serial.println("ALARM 2 TRIGGERED!");
    servo.write(90);
    delay(1500);
    servo.write(0);
  }

  if ((now.hour() == 14) && (now.minute() == 56) && (now.second() == 30))
  {
    Serial.println("ALARM 3 TRIGGERED!");
    servo.write(90);
    delay(1500);
    servo.write(0);
  }
}
