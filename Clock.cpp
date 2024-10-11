#include <Wire.h>         
#include <RTClib.h>       
#include <LiquidCrystal.h> 

// Initialize RTC and LCD objects
RTC_DS3231 rtc;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // LCD pins: RS, E, D4, D5, D6, D7

void setup() {
  lcd.begin(16, 2);  
  Serial.begin(9600); 
  
  // Initialize RTC module
  if (!rtc.begin()) {
    lcd.print("RTC not found!"); // Display error if RTC is not detected
    while (1); // Halt execution if RTC fails
  }

  
  rtc.adjust(DateTime(F(_DATE), F(TIME_)));

  if (rtc.lostPower()) {
    // If the RTC lost power, set the time to a default value
    rtc.adjust(DateTime(2023, 10, 11, 0, 0, 0)); // Set to specific date and time
  }
}

void loop() {
  // Fetch current date and time from the RTC
  DateTime now = rtc.now();

  // Display the current time on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.minute());
  lcd.print(':');
  lcd.print(now.second());

  // Display the current date on the LCD
  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  lcd.print(now.day());
  lcd.print('/');
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());

  delay(1000); // Update every second
}

/* 
 *  -----------------------------------------------------------------
 *  Copyright (c) 2024 M Dawood. All rights reserved.
 *  This code is provided for educational purposes and is open for modification.
 *  Redistribution of this code or parts of it is allowed as long as
 *  proper credit is given to the original author.
 *  
 *  Author: M Dawood
 *  -----------------------------------------------------------------
 */
