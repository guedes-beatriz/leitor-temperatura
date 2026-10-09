#include <Arduino.h>
#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT11
#define pinoBuzzer 18
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(pinoBuzzer, OUTPUT);
  pinMode (33, OUTPUT);
  pinMode (32, OUTPUT);
  pinMode (27, OUTPUT);
  Serial.begin(115200);
  dht.begin();
 
}

void loop() {
   digitalWrite(pinoBuzzer, HIGH); // Liga o buzzer (emite som)
  delay(1000);                    // Espera 1 segundo (1000 ms)
  digitalWrite(pinoBuzzer, LOW);  // Desliga o buzzer
  delay(1000); 

  digitalWrite(33, HIGH);
  delay(1000);
  digitalWrite(33, LOW);
  delay(1000);
  digitalWrite(32, HIGH);
  delay(1000);
  digitalWrite(32, LOW);
  digitalWrite(27, HIGH);
  delay(1000);
  digitalWrite(27, LOW);

  delay(2000);
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(umidade)|| isnan(temperatura)){
    Serial.println ("Falha ao ler o DHT11");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print (temperatura);
  Serial.print (" °C | Umidade: % ");
  Serial.print(umidade);
 
}
 