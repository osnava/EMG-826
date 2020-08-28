/*💪 Visualize your muscle activity in LabVIEW and create a text file.
Create .txt file in LabVIEW https://bit.ly/32wjRNJ

  @author   Oscar Navarrete
-Pinout Diagrams:

Arduino UNO   https://bit.ly/30Axk7l
Arduino NANO  https://bit.ly/31uYJH1
Arduino MEGA  https://bit.ly/3fxND9e
EMG-826       https://bit.ly/3g4P3YV
1N5819        https://bit.ly/2QxgHUg
-Connections:
---------------------------
Cable | Muscle's electrodes
---------------------------
Black | Bone
Red   | Middle
Blue  | End
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
*/

int Muscle; //Declare this variable to store analog read.

void setup() {
  Serial.begin(9600); //Begin serial communication.
}

void loop() {
  Muscle = analogRead(A0); //Here A0 was chosen but you can choose any analog channel.
  Serial.println(Muscle); //Red signal
}
