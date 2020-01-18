/*
 * AttTiny85 pinout
 *                          +----||---+
 *        (Reset)     PB5 --+ 1     8 +-- VCC      [+5V]
 *                    PB3 --+ 2     7 +-- PB2
 * [PowerControl]     PB4 --+ 3     6 +-- PB1
 *                    GND --+ 4     5 +-- PB0
 *                          +---------+
 *
 *                +------[||||]------------------+
 *                |      100K                    |
 *                |          +---||---+          |
 *                +----------+1      8+----------O-------- VCC (+5 V)
 *                           |        |
 +                           |        |
 *       Power Control       |        |
 *            O--------------+3       |
 *                        +--+4       |                                            
 *                        |  +--------+
 *                        |                      
 *                        |                       
 *                        O-------------------------------  GND
 */

#define POWER_CONTROL_PIN 4 // PB4 is pin 3 on the chip
#define TIMEOUT 95000  // Timeout = 1 minute and 35 seconds (in milliseconds). That is how long it takes for the WiFi router to boot up.
                       // Remember to "BurnBootloader" once so the chip fuses are configured for desired frequency.
                       // If the settings in Arduino are different than the way fuses are burned, the sketch will not have the correct timing.

// We only need the chip to do something when it is powered on, after that the POWER_CONTROL_PIN state should remain HIGH.
void setup() {
  pinMode(POWER_CONTROL_PIN,  OUTPUT);

  // NORMAL OFF outlets are OFF, NORMAL ON outlets are ON:
  digitalWrite(POWER_CONTROL_PIN, LOW);

  // Wait the specified amount of time before switching the POWER_CONTROL_PIN state:
  delay(TIMEOUT);

  // NORMAL OFF outlets are ON, NORMAL ON outlets are OFF:
  digitalWrite(POWER_CONTROL_PIN, HIGH);
}

void loop()
{
  // The controller does not do anything after it flipped the switch.
  // That only needs to happen once at boot time.
}
