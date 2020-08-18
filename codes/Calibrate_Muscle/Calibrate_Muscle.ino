/*Use this code to calibrate your sensor. Know what's your minimum and maximum values.
  
  @author   Oscar Navarrete

-Pinout Diagrams:
Arduino UNO   https://bit.ly/30Axk7l
Arduino NANO  https://bit.ly/31uYJH1
Arduino MEGA  https://bit.ly/3fxND9e
EMG-826       https://bit.ly/3g4P3YV

-Connections:
---------------------------
Cable | Muscle's electrodes
---------------------------
Black | Bone
Red   | Middle
Blue  | End
---------------------------
if you want to use Arduino's 5V use this:
-----------------
Arduino | EMG-826
-----------------
5V      |  V+*
GND     |  GND
A0      |  Muscle
-----------------

if you want to use external supply just make sure to have all GNDs connected:
-----------------------------------
External Supply | Arduino | EMG-826
-----------------------------------
      GND       |   GND   |  GND
      V+*       |         |  V+*
                |   A0    |  Muscle
-----------------------------------       
*V+ can work with 5-9V range but you must not exceed 5V when using a microncontroller
like Arduino UNO, Nano, Mega.

*/

//After uploading this code, type this commmand on your keyboard: ctrl + shift + M

int Muscle; //Declare this variable to store analog read.
unsigned long time_time; //Variable that stores the time during the loop.
unsigned long tense_relax;
String words[] ={"T E N S E","R E L A X"};
const int desired_time = 10; //Change the value if you want more calibration time (seconds)
int maxx=0; 
int minn= 1023;
bool k;
void setup() {
  Serial.begin(9600); //Begin serial communication.
  Serial.println("E  M  G  -  8  2  6\n");
  Serial.println("This is a "+String(desired_time)+" seconds calibration mode"); delay(1000);
  Serial.println("During 2 seconds tense the muscle and relax 2 seconds"); delay(1000);
  Serial.print("Wait the countdown to begin calibration");delay(1000);
  Serial.print(".");delay(1000);Serial.print(".");delay(1000);Serial.println(".");delay(1000);
  Serial.print("3 "); delay(1000);Serial.print("2 "); delay(1000);Serial.println("1");delay(1000);
  Serial.print("G O ! ! ! \n\n\n");
  time_time   = millis();
  tense_relax = millis();
  do{
    Muscle = analogRead(A0); //Here A0 was chosen but you can choose any analog channel.
    delay(1);
    maxx = max(Muscle,maxx);
    minn = min(Muscle,minn);
    
    if(millis()-tense_relax>2000){
      Serial.println(words[k]);
      tense_relax = millis();
      k = !k;}
    }while(millis()-time_time < desired_time*1000);

   Serial.print("Maximum value in bits = "); Serial.println(maxx);
   Serial.print("Minimum value in bits = "); Serial.println(minn);  
}

void loop() {}
