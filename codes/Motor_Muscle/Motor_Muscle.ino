/*Use your strength to control the speed and rotation direction of a DC motor with L298N driver
 ⚠ IF YOU WANT THIS CODE TO PROPERLY WORK YOU MUST USE TWO EMG-826 SENSORS ⚠

  @author   Oscar Navarrete
  
-Pinout Diagrams:
Arduino UNO   https://bit.ly/30Axk7l
Arduino NANO  https://bit.ly/31uYJH1
Arduino MEGA  https://bit.ly/3fxND9e
L298N         https://bit.ly/3aBUjlF
EMG-826       https://bit.ly/3g4P3YV


-Connections:
---------------------------
Cable | Muscle's electrodes
---------------------------
Black | Bone
Red   | Middle
Blue  | End
---------------------------

-------------------------------------------------------------------------
Arduino | EMG-826   |EMG-826 (2) | L298N | 12V DC Motor | External Supply
-------------------------------------------------------------------------
5V      |  V+       | V+         |       |               |
GND     |  GND      | GND        |  GND  |               |  - terminal
A0      |  Muscle   |            |       |               |
A1      |           | Muscle     |       |               |               
D9      |           |            |  ENA  |               |
D8      |           |            |  IN1  |               |
D7      |           |            |  IN2  |               |
        |           |            |  OUT1 |   Motor       |
        |           |            |  OUT2 |   Motor       |
        |           |            |  VCC  |               |  + terminal
------------------------------------------------------------------------
*/

const byte ENA  = 9;     //PWM pin 
const byte dir1 = 8;     //Direction pin
const byte dir2 = 7;     //Direction pin

//If you want to know what's the maximum value, you  should use Calibrate_Muscle.ino
//at https://bit.ly/315BXXg
//If the maximum result (e.g.) was 1000, set maxval = 900
const int maxval = 400;  

int muscle;    //With this muscle you will control motor speed
int muscle_2;  //With this muscle you will control motor rotation direction

bool state = false; //Fake button

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  // Set initial rotation direction
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH);
}

void loop() {
  muscle = map(analogRead(A0), 0, 1023, 0 , 255); //Map the muscle value from 0 to 255
  analogWrite(ENA, muscle); //Send PWM signal
  muscle_2 = analogRead(A1); //Read this muscle to change rotation direction
  if(muscle_2 > maxval){
    state = !state;
    
    digitalWrite(dir1, state);
    digitalWrite(dir2, !state);    
    }
   delay(50);
}
