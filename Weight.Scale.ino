#include "HX711.h"

// Pinos do HX711
#define DOUT A1
#define CLK  A0

HX711 balanca;

// LED RGB (catodo comum)
#define RED_PIN   2
#define GREEN_PIN 4
#define BLUE_PIN  8

// Buzzer
#define BUZZER_PIN 7

unsigned long lastBeepTime = 0;

// Valor inicial de calibração — será ajustado depois com pesos reais
float calibration_factor = 22000.0; // ajuste após testes

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando balança com 4 células...");

  balanca.begin(DOUT, CLK);
  balanca.set_scale(calibration_factor);
  balanca.tare(); // zera a balança

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("Balança pronta! Coloque peso para testar.");
}

void loop() {
  float peso = balanca.get_units(10); // média de 10 leituras
  if (peso < 0) peso = 0;

  Serial.print("Peso detectado: ");
  Serial.print(peso, 2);
  Serial.println(" kg");

  // LED e buzzer com base nas faixas de peso
  if (peso >= 0.5 && peso < 2.0) {
    setColor(0, 255, 0);  // Verde
    acionarBuzzerSimples(1000, 3000);
  }
  else if (peso >= 2.0 && peso <= 3.0) {
    setColor(255, 255, 0); // Amarelo
    acionarBuzzerSimples(1000, 3000);
  }
  else if (peso > 3.0) {
    setColor(255, 0, 0);   // Vermelho
    acionarBuzzerDuplo(200, 2000);
  }
  else {
    setColor(0, 0, 0);     // LED apagado
  }

  delay(300);
}

// ---------- Funções auxiliares ----------

void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

void acionarBuzzerSimples(int duracao, int intervalo) {
  unsigned long tempoAtual = millis();
  if (tempoAtual - lastBeepTime >= intervalo) {
    tone(BUZZER_PIN, 1000, duracao);
    lastBeepTime = tempoAtual;
  }
}

void acionarBuzzerDuplo(int duracao, int intervalo) {
  unsigned long tempoAtual = millis();
  if (tempoAtual - lastBeepTime >= intervalo) {
    tone(BUZZER_PIN, 1000, duracao);
    delay(300);
    tone(BUZZER_PIN, 1000, duracao);
    lastBeepTime = tempoAtual;
  }
}
