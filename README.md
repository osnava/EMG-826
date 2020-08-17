# :muscle: EMG-826 
It looks like your QR scanner worked perfectly. Enjoy this repository!
## :warning: WARNING :warning:
THIS IS NOT A MEDICAL DEVICE.
IMPROPER USE OF THIS SENSOR COULD CAUSE HARM TO THE SUBJECT.
YOU MUST BE INFORMED BEFORE USING IT. DON'T TAKE RISKS.
READ THE MANUAL AND DON'T HESITATE TO ASK QUESTIONS. 

<img src="images/sensor.png" alt="drawing" width="300"/>


## Description
In this repository you will find example codes to use your board. Stop complaining about using libraries, you don't need them: just plug and play!

EMG-826 it's a [sEMG](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3821366/) (surface Electromyography) sensor fully compatible with:

* Arduino
* ST
* PIC
* MSP430
* and more...

It has a variable resistor to amplify the output signal (Muscle pin). If you are curious about how a pure EMG signal looks, it has the Raw pin wich can be attached to an oscilloscope to see the pure signal.
There's no need to use dual voltage supply thanks to it's IC that converts single to dual supply. 
If you want to use it with an Arduino board just connect 5V to the V+ pin and GND to GND pin. For the Raw signal you can supply up to 9V on the V+ pin.

## Muscle connections 
Read this: [Muscles of the Arm and Hand](https://doctorlib.info/anatomy/classic-human-anatomy-motion/7.html#:~:text=MUSCLE%20DIAGRAM)

<img src="https://doctorlib.info/anatomy/classic-human-anatomy-motion/classic-human-anatomy-motion.files/image253.jpg" alt="drawing" width="420"/>

#### Arm

<img src="https://doctorlib.info/anatomy/classic-human-anatomy-motion/classic-human-anatomy-motion.files/image254.jpg" alt="drawing" width="50"/>  **Deltoid Muscle** 
<img src="https://doctorlib.info/anatomy/classic-human-anatomy-motion/classic-human-anatomy-motion.files/image255.jpg" alt="drawing" width="50"/>  **Flexor Muscle (Upper)**

<img src="https://doctorlib.info/anatomy/classic-human-anatomy-motion/classic-human-anatomy-motion.files/image256.jpg" alt="drawing" width="50"/>  **Extensor Muscle(Upper)**
<img src="https://doctorlib.info/anatomy/classic-human-anatomy-motion/classic-human-anatomy-motion.files/image257.jpg" alt="drawing" width="50"/>  **Brachioradialis Muscle**

<img src="https://doctorlib.info/anatomy/classic-human-anatomy-motion/classic-human-anatomy-motion.files/image258.jpg" alt="drawing" width="50"/>  **Extensor Muscle (Superfical Layer)** 
<img src="https://doctorlib.info/anatomy/classic-human-anatomy-motion/classic-human-anatomy-motion.files/image259.jpg" alt="drawing" width="50"/>  **Flexor Muscle (Lower)**

<img src="https://doctorlib.info/anatomy/classic-human-anatomy-motion/classic-human-anatomy-motion.files/image260.jpg" alt="drawing" width="50"/>  **Extensor Muscle (Deep Layer)**

#### Hand

<img src="https://doctorlib.info/anatomy/classic-human-anatomy-motion/classic-human-anatomy-motion.files/image261.jpg" alt="drawing" width="50"/>  **Thenar Muscle**
<img src="https://doctorlib.info/anatomy/classic-human-anatomy-motion/classic-human-anatomy-motion.files/image262.jpg" alt="drawing" width="50"/>  **Hypothenar Muscle**
<img src="https://doctorlib.info/anatomy/classic-human-anatomy-motion/classic-human-anatomy-motion.files/image263.jpg" alt="drawing" width="50"/>  **Dorsal Interosseeous Muscle**

#### Electrodes
<img src="images/electrodo_red.png" alt="drawing" width="100"/>   <img src="images/electrodo_blue.png" alt="drawing" width="100"/>   <img src="images/electrodo_black.png" alt="drawing" width="100"/>

Choose a muscle and make sure your skin is dry and clean. Put one electrode **(red)** in the middle of the muscle and another one at the end **(blue)**, put a third electrode **(black)** in a bony zone (e.g. elbow).

## EMG-826 + Arduino
To connect the sensor to Arduino you just need to follow the instructions in every code [here](codes/). You can use the image below as reference to make the appropriate connections.

<img src="images/arduino.png" alt="drawing" width="800"/>

You can begin to use this sensor by uploading this [code](codes/Plot_Muscle/Plot_Muscle.ino) below:


```C++
int Muscle; //Declare this variable to store analog read.

void setup() {
  Serial.begin(9600); //Begin serial communication.
}

void loop() {
  Muscle = analogRead(A0); //Here A0 was chosen but you can choose any analog channel.
  Serial.println(" ");
  Serial.print(440);       //Select a value between 0-1023
  Serial.print(" ");
  Serial.print(0);    
  Serial.print(" ");
  Serial.println(Muscle); //Red signal
}
```
## EMG-826 + Oscilloscope
This sensor has a wide voltage supply range (5-9V). If you want to know how your raw EMG signal looks like, follow this image below:

<img src="images/SCOPE.png" alt="drawing" width="1000"/>
