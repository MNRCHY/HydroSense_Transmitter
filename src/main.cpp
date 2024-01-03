#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <DHT.h>

#define DHT_PIN 22 // Pin DHT
#define DHT_TYPE DHT11 // Type DHT

DHT dht(DHT_PIN, DHT_TYPE);
float humidity = 0;

const int analogPin = 4; // Pin analog untuk membaca kelembaban tanah
const int threshold = 1500; // Ambang batas untuk menentukan kondisi basah atau kering

RF24 radio(15, 21); // CE, CSN
const byte address[6] = "00001";

void readTemp();

void setup() {
  Serial.begin(9600);
  dht.begin();
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  // readTemp();
  // Serial.print("Kelembaban DHT11: ");
  // Serial.println(humidity, 2);


  int sensorValue = analogRead(analogPin);
  const int text[] = {sensorValue};
  radio.write(&text, sizeof(text));
  delay(5000);
}

// void readTemp() {
//   humidity = dht.readHumidity();
// }
