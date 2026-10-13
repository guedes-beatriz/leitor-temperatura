#include <Arduino.h>
#include <DHT.h>

// Pinos dos componentes
#define DHTPIN 4
#define DHTTYPE DHT11
#define PINO_BUZZER 18

#define LED1 33
#define LED2 32
#define LED3 27

// Modos de funcionamento
#define MODO_DESLIGADO  0
#define MODO_LIGADO     1
#define MODO_AUTOMATICO 2

// Modo atual (0 = Desligado, 1 = Ligado, 2 = Automático)
int modo = MODO_LIGADO;

// Limite de temperatura para acionar o buzzer (em °C)
const float LIMITE_TEMPERATURA = 30.0;

DHT dht(DHTPIN, DHTTYPE);

// Controle de tempo para ler o sensor a cada 2 segundos
unsigned long tempoAnterior = 0;
const unsigned long intervaloLeitura = 2000;

void setup() {
  Serial.begin(115200);

  // pinos
  pinMode(PINO_BUZZER, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  // buzzer começa desligado
  digitalWrite(PINO_BUZZER, LOW);

  // inicia o sensor
  dht.begin();

  Serial.println("Sistema iniciado!");
}

void loop() {
  //teste para mudança de modos(provisório)
  if (Serial.available() > 0) {
    char comando = Serial.read();

    if (comando == '0') {
      modo = MODO_DESLIGADO;
      Serial.println("\n [TESTE] Modo alterado para: 0 (DESLIGADO)");
    } else if (comando == '1') {
      modo = MODO_LIGADO;
      Serial.println("\n [TESTE] Modo alterado para: 1 (LIGADO)");
    } else if (comando == '2') {
      modo = MODO_AUTOMATICO;
      Serial.println("\n [TESTE] Modo alterado para: 2 (AUTOMÁTICO)");
    }
  }

  unsigned long tempoAtual = millis();

  switch (modo) {
    case MODO_DESLIGADO:
      // Apenas 1 LED ligado e buzzer desligado
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(PINO_BUZZER, LOW);
      break;

    case MODO_LIGADO:
      // 2 LEDs ligados
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);

      // Lê e mostra temperatura e umidade a cada 2 segundos
      if (tempoAtual - tempoAnterior >= intervaloLeitura) {
        tempoAnterior = tempoAtual;

        float umidade = dht.readHumidity();
        float temperatura = dht.readTemperature();

        if (isnan(temperatura) || isnan(umidade)) {
          Serial.println("Erro ao ler o sensor DHT11!");
        } else {
          Serial.print("Temperatura: ");
          Serial.print(temperatura, 1);
          Serial.print(" °C | Umidade: ");
          Serial.print(umidade, 1);
          Serial.println(" %");

          // Apita o buzzer se a temperatura for igual ou superior ao limite
          if (temperatura >= LIMITE_TEMPERATURA) {
            digitalWrite(PINO_BUZZER, HIGH);
            delay(2000);
            digitalWrite(PINO_BUZZER, LOW);
            delay(2000);
          } else {
            digitalWrite(PINO_BUZZER, LOW);
          }
        }
      }
      break;

    case MODO_AUTOMATICO:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);

      // Lê e mostra temperatura e umidade a cada 2 segundos
      if (tempoAtual - tempoAnterior >= intervaloLeitura) {
        tempoAnterior = tempoAtual;

        float umidade = dht.readHumidity();
        float temperatura = dht.readTemperature();

        if (isnan(temperatura) || isnan(umidade)) {
          Serial.println("Erro ao ler o sensor DHT11!");
        } else {
          Serial.print("Temperatura: ");
          Serial.print(temperatura, 1);
          Serial.print(" °C | Umidade: ");
          Serial.print(umidade, 1);
          Serial.println(" %");

          // Apita o buzzer se a temperatura for igual ou maior ao limite
          if (temperatura >= LIMITE_TEMPERATURA) {
            digitalWrite(PINO_BUZZER, HIGH);
            delay(2000);
            digitalWrite(PINO_BUZZER, LOW);
            delay(2000);
          } else {
            digitalWrite(PINO_BUZZER, LOW);
          }
        }
      }
      break;

    default:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(PINO_BUZZER, LOW);
      break;
  }
}