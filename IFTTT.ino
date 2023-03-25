#include "Particle.h"
int uv;
String uv_data;
bool sun =FALSE;
bool nosun = TRUE;
SYSTEM_THREAD(ENABLED);



void setup() {
   pinMode(A5, INPUT);
}

void loop() {
    uv = analogRead(A5);
    uv_data = String(uv);
    if (uv > 20){
        if(!sun){
            Particle.publish("sunlight", "Under slight at: "+ uv_data +" UV intensity"); 
            sun = !sun;
            nosun =!nosun; 
        }
        
    }
    else if(uv < 20){
        if(!nosun){
            Particle.publish("sunlight", "Not under sunlight"); 
            sun = !sun;
            nosun =!nosun;            
        }
          
    }
    delay(1000);
}
