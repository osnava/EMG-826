/*💪 Make a strength meter with LEDs
  @author   Oscar Navarrete
-Pinout Diagrams:
Arduino UNO   https://bit.ly/30Axk7l
Arduino NANO  https://bit.ly/31uYJH1
Arduino MEGA  https://bit.ly/3fxND9e
EMG-826       https://bit.ly/3g4P3YV
Red LED       https://bit.ly/31rkdVc
1N5819 Diode  https://bit.ly/2QxgHUg

-Connections:
---------------------------
Cable | Muscle's electrodes
---------------------------
Black | Bone
Red   | Middle
Blue  | End
---------------------------
LEDs:
---------
Arduino | 
---------
D2      |  LED_2 (anode)
D3      |  LED_3 (anode)
D4      |  LED_4 (anode)
D5      |  LED_5 (anode)
D5      |  LED_6 (anode)
*Every LEDs' cathode needs to have a 330Ω resistor connected to GND.

---------------------------
if you want to use Arduino's 5V use this:
-------------------------
Arduino | EMG-826 | 1N5819
-------------------------
5V      |  V+*    |
GND     |  GND    |
        |  Muscle | Anode
A0      |         | Cathode
-------------------------

if you want to use external supply just make sure to have all GNDs connected:
---------------------------------------------
External Supply | Arduino | EMG-826 | 1N5819
---------------------------------------------
      GND       |   GND   |  GND    |
      V+*       |         |  V+*    |
                |         |  Muscle | Anode
                |   A0    |         | Cathode
---------------------------------------------   
*V+ can work with 5-9V range but you must not exceed 5V when using a microncontroller
like Arduino UNO, Nano, Mega.

After uploading this code, type this commmand on your keyboard: ctrl + shift + L to
visualize your muscle's activity.

*/

int Muscle; //Declare this variable to store analog read.
int levels[] = {0,0,0,0,0}; //Define an empty array.
const byte leds[] = {2,3,4,5,6}; //Digital Pins.
int i; //Incremental variable
void setup() {
  for(i=2; i<=6; i++){
    pinMode(i, OUTPUT);} //Set digital pins 2-6 as outputs.

  for(i=0; i<6; i++){    //Use a for loop to define the levels.
    if(i==5) break;
    levels[i] = (i+1)*1000/5;
    }                              
}

void loop() {
  Muscle = analogRead(A0); //Here A0 was chosen but you can choose any analog channel.
  delay(1);                //A small delay so the ADC doesn't saturate.
  for(i=0; i<5; i++){      //A for loop to compare the muscle and the level value.
    if(Muscle>=levels[i]){
      digitalWrite(leds[i], HIGH);         
      }
    else{
      digitalWrite(leds[i],LOW);
      }
    }

}
