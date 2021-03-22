#include <mbed.h>
#include <USBSerial.h>

#include <math.h>

// DigitalOut led1(LED1);

// void toggleLED(void) {
//   led1 = !led1;
// }


USBSerial serial;

PwmOut led1(LED1);

#define PI 3.14159265

void sineOutput(void) {

  // count variable initialised at startup but local to function
  static uint32_t count = 0;

  // increment count at 1000Hz
  count++;

  // calculate the time
  float t1 = (float)count/1000.0;

  // pick a frequency
  float frequency = 0.5;

  // calculate sin value from radians per second
  float sineVal = sin(2*PI*frequency*t1);
  
  // sin \in [-1,1] .... divide by 2 and bias by 0.5 
  // output \in [0, 1]
  led1.write((sineVal/2)+0.5);
}

int main() {
  
  // 20ms period
  led1.period(0.02);

  // 50% duty cycle
  led1.write(0.5);

  
  Ticker t;

  // point to output function, 1000Hz frequency
  t.attach(&sineOutput, 0.001);

  while(1) {

    // led1 = !led1;
    wait_ms(500);
  }


}













// #include <mbed.h>
// #include <USBSerial.h>

// DigitalOut led1(LED1);
// AnalogIn   ain(PA_1);



// void interruptFunction(void) {
//   led1 = !led1;
// }


  // led.period(0.02f);      // 4 second period
  // led.write(0.20f);


// int main() {

//   USBSerial serial;
//   // Ticker t;
//   // t.attach(&interruptFunction, 1.0);

//   float valArray[100];
//   int i = 0;
//   while(1) {

//     float aVal = ain.read();

//     valArray[i++] = aVal;
//     if (i >= 100) {
//       serial.printf("data:\n\r");
//       for (i = 0; i < 100; i++) {
//         serial.printf("%.2f\n\r", valArray[i]);
//       }
//       i = 0;
//       wait_ms(1000);
//     }
//     // float aVal = 0;
//     // serial.printf("analog val: %.2f\n\r", aVal);
//     // serial.printf("%.2f\n\r", aVal);
//     wait_ms(1);

//   }


// }