/*Control a servo motor with your muscle
  @author   Oscar Navarrete
-Pinout Diagrams:
Arduino UNO  | https://bit.ly/30Axk7l
Arduino NANO | https://bit.ly/31uYJH1
Arduino MEGA | https://bit.ly/3fxND9e
EMG-826      |
SG90         | https://bit.ly/30A7gJw

-Connections:
---------------------------
Cable | Muscle's electrodes
---------------------------
Black | Bone
Red   | Middle
Blue  | End
---------------------------
if you want to use Arduino's 5V use this:
---------------------------
Arduino | EMG-826 |  SG90
---------------------------
5V      |  V+*    |  Red
GND     |  GND    |  Brown
A0      |  Muscle |   -
D3      |    -    |  Orange
---------------------------

if you want to use external supply just make sure to have all GNDs connected:
------------------------------------------
External Supply | Arduino | EMG-826 | SG90**
------------------------------------------
      GND       |   GND   |  GND    | Brown
      V+*       |    -    |  V+*    | Red
       -        |   A0    |  Muscle |   -
       -        |   D3    |     -   | Orange
-----------------------------------       
*V+ can work with 5-9V range but you must not exceed 5V when using a microncontroller
like Arduino UNO, Nano, Mega.
**If you are going to use a servo motor use V+ = 5V.
*/
#include <Servo.h> 

int Muscle;        //Declare this variable to store analog read.
int Deg;           //Variable to store degrees to spin
Servo servo_motor; //Create Servo object called servo_motor

void setup() {
  servo_motor.attach(3);  // attaches the servo on pin 3 to the servo_motor object
}

void loop() {
  Muscle = analogRead(A0);            //Here A0 was chosen but you can choose any analog channel.
  Deg = map(Muscle, 0, 1023, 0, 180); // scale it to use it with the servo (value between 0 and 180)
  servo_motor.write(Deg);             // sets the servo position according to the scaled value
  delay(10);                          // waits for the servo to get there
}
