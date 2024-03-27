// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library
#include <SPI.h>

// Create Amplitude Shift Keying Object on pin 10
RH_ASK rf_driver;
int vib_pin = 2;

void setup()
{
    pinMode(vib_pin, OUTPUT); // set vibration module pin as output
    digitalWrite(vib_pin, HIGH); // turn on vibration module
    delay(500);
    digitalWrite(vib_pin, LOW); // turn off vibration module
    // Initialize ASK Object
    if (!rf_driver.init()){
        Serial.println("init failed");
    }
    // Setup Serial Monitor
    Serial.begin(9600);
    Serial.println("Receiver is ready");

}

void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[11];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {

      // Message received with valid checksum
      Serial.print("Message Received: ");
      Serial.println((char*)buf);
      digitalWrite(vib_pin, HIGH); // turn on vibration module
      delay(500);
      digitalWrite(vib_pin, LOW); // turn off vibration module
    }
}
