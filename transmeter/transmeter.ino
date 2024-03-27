// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library
#include <SPI.h>

#define TIMEOUT 2000
// Create Amplitude Shift Keying Object on pin 10
RH_ASK rf_driver;

void setup()
{
    Serial.begin(9600);
    Serial.println("init start");
    // Initialize ASK Object
    rf_driver.init();
    if (!rf_driver.init()){
        Serial.println("init failed");
    }
    // Set up LED pin as output
    pinMode(LED_BUILTIN, OUTPUT);

    //flash LED to indicate transmitter is ready
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
    }
    
}

void loop()
{
    Serial.println("start message send");
    digitalWrite(LED_BUILTIN, HIGH);

    const char *msg = "Hello";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();

    Serial.println("message send");

    digitalWrite(LED_BUILTIN, LOW);
    delay(TIMEOUT);
}
