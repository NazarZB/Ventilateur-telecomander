//For Ir Remote
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

//For DC motor
#include <L293D.h>

L293D motor(6,5,4);

IRrecv irReceiver(2);
decode_results results;


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
irReceiver.enableIRIn();
motor.set(0);
}

void loop() {
  // put your main code here, to run repeatedly:

  
  if (irReceiver.decode(&results)) {
    // le code infrarouge est dans la variable results.value
    Serial.println(results.value);
    irReceiver.resume();
    
if (results.value == 16724175)
  {
  motor.set(150);
  }
if (results.value == 16718055)
  {motor.set(200);
  }
if (results.value == 16743045)
  {motor.set(250);
  }
if (results.value == 16753245)
  {motor.set(0);
  }

}


    
}
