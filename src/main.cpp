#include <Arduino.h>
#include <DHT.h>
#include <WiFi.h>
#include <WebServer.h> 
#include "index.h"
#include "ligado.h"  
#include "desligado.h"
#include "automatico.h"

const char* ssid = "NOMEDAREDE";
const char* password = "SENHADAREDE";

WebServer server(80);

#define DHTPIN 4
#define DHTTYPE DHT11
#define PINO_BUZZER 18

#define LED1 27 //amarelo
#define LED2 33 //verde
#define LED3 32 //azul

#define MODO_DESLIGADO  0
#define MODO_LIGADO     1
#define MODO_AUTOMATICO 2

// Modo atual (0 = Desligado, 1 = Ligado, 2 = Automático)
int modo = MODO_LIGADO;

// Limite de temperatura para acionar o buzzer (em °C)
const float LIMITE_TEMPERATURA = 30.0;
const float LIMITE_DESLIGAR = 28.0;      // temperatura para desligar buzzer e alerta
float temp = 0.0;
float umid = 0.0;

DHT dht(DHTPIN, DHTTYPE);

// Controle de tempo para ler o sensor a cada 2 segundos
unsigned long tempoAnterior = 0;
const unsigned long intervaloLeitura = 2000;

void setup() {
  Serial.begin(115200);

  // pagina inicial 
  server.on("/", []() {
    server.send(200, "text/html", pagina_html);
  });

  // quando o usuário entrar em /ligado
  server.on("/ligado", []() {
    modo = MODO_LIGADO; // Muda o modo dos LEDs/sensor para Ligado
    server.send(200, "text/html", pagina_ligado); // Entrega a tela do ligado.h
  });

  //  quando o usuário entrar em /automatico
  server.on("/automatico", []() {
    modo = MODO_AUTOMATICO; // Muda o modo dos LEDs/sensor para Automático
    server.send(200, "text/html", pagina_automatico); // Entrega a tela do automatico.h
  });

  //  quando o usuário entrar em /desligado
  server.on("/desligado", []() {
    modo = MODO_DESLIGADO; // Muda o modo dos LEDs/sensor para Desligado
    server.send(200, "text/html", pagina_desligado); // Entrega a tela do desligado.h
  });

  // rota que entrega a temperatura e umidade em tempo real (JSON)
  server.on("/dados", []() {
    String json = "{\"temperatura\":" + String(temp, 1) + ",\"umidade\":" + String(umid, 1) + "}";
    server.send(200, "application/json", json);
  });

WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.print("\nConectado! IP da ESP32: ");
Serial.println(WiFi.localIP()); 

  server.begin();

  
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
  server.handleClient();

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
      // LED 2 ligado
      digitalWrite(LED1, LOW);
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
          temp = temperatura;
          umid = umidade;
          Serial.print("Temperatura: ");
          Serial.print(temperatura, 1);
          Serial.print(" °C | Umidade: ");
          Serial.print(umidade, 1);
          Serial.println(" %");

          // Apita o buzzer se a temperatura for igual ou superior ao limite
        if (temperatura >= LIMITE_TEMPERATURA) {
            digitalWrite(PINO_BUZZER, HIGH);
        } else {
            digitalWrite(PINO_BUZZER, LOW);
          }
        }
      }
      break;

    case MODO_AUTOMATICO:
     // Led 3 ligado
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);

      // Lê e mostra temperatura e umidade a cada 2 segundos
      if (tempoAtual - tempoAnterior >= intervaloLeitura) {
        tempoAnterior = tempoAtual;

        float umidade = dht.readHumidity();
        float temperatura = dht.readTemperature();

        if (isnan(temperatura) || isnan(umidade)) {
          Serial.println("Erro ao ler o sensor DHT11!");
        } else {
          temp = temperatura;
          umid = umidade;
          Serial.print("Temperatura: ");
          Serial.print(temperatura, 1);
          Serial.print(" °C | Umidade: ");
          Serial.print(umidade, 1);
          Serial.println(" %");

          // controle do buzzer no modo automático
        if (temperatura >= LIMITE_TEMPERATURA) {
          digitalWrite(PINO_BUZZER, HIGH);
          } else if (temperatura <= LIMITE_DESLIGAR) {
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