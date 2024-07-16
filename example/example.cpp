#include <Arduino.h>

#include <MultiVariable.h>

void setup() {
  Serial.begin(9600);

  String text = "Hello world";

  MultiVariable* valuer = createNewVariable();

  valuer->setChar(valuer, 'A');
  Serial.println(valuer->getChar(valuer));
  delay(200);
  valuer->setCharArr(valuer, "Hello world");
  Serial.println(valuer->getCharArr(valuer));
  delay(200);

  valuer->setInteger(valuer, 1);
  Serial.println(valuer->getInteger(valuer));
  delay(200);


  valuer->setString_ptr(valuer, &text);

  Serial.println(valuer->getString(valuer));
  delay(200);

  valuer->setBool(valuer, true);
  Serial.println(valuer->getBool(valuer));
  delay(200);

  uint var = 45;
  valuer->setUinteger_ptr(valuer, &var);
  Serial.println(valuer->getUinteger(valuer));
  delay(200);
  var -= 40;
  Serial.println(valuer->getUinteger(valuer));
  delay(200);

}

void loop() {
  
}