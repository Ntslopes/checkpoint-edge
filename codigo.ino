#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin = A0;     // LDR
int tempPin = A1;       // TMP36
int umidadePin = A2;    // Potenciometro

int ledVermelho = 10;
int ledAmarelo = 9;
int ledVerde = 8;

int buzzer = 7;

float mediaTemperatura;
int mediaLuz;
int mediaUmidade;

void setup() {

  Serial.begin(9600);

  pinMode(sensorPin, INPUT);
  pinMode(tempPin, INPUT);
  pinMode(umidadePin, INPUT);

  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  pinMode(buzzer, OUTPUT);

  // LCD
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Sistema");

  lcd.setCursor(0,1);
  lcd.print("Iniciado");

  delay(2000);

  lcd.clear();
}

void loop() {


  int somaLuz = 0;
  int somaUmidade = 0;
  float somaTemperatura = 0;

  for(int i = 0; i < 5; i++) {


    int valor_ldr = analogRead(sensorPin);

    int ldr_modificado = map(valor_ldr, 207, 1012, 0, 1023);

    somaLuz += ldr_modificado;


    int leituraTemp = analogRead(tempPin);

    float voltagem = leituraTemp * 5.0;
    voltagem /= 1024.0;

    float temperatura = (voltagem - 0.5) * 100;

    somaTemperatura += temperatura;


    int leituraUmidade = analogRead(umidadePin);

    int umidade = map(leituraUmidade, 0, 1023, 0, 100);

    somaUmidade += umidade;

    delay(100);
  }

  mediaLuz = somaLuz / 5;
  mediaTemperatura = somaTemperatura / 5;
  mediaUmidade = somaUmidade / 5;


  Serial.print("Luz: ");
  Serial.print(mediaLuz);

  Serial.print(" | Temp: ");
  Serial.print(mediaTemperatura);

  Serial.print(" | Umidade: ");
  Serial.print(mediaUmidade);
  Serial.println("%");



  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  digitalWrite(buzzer, LOW);

  lcd.clear();

  if(mediaLuz < 300) {

    // Ambiente escuro
    digitalWrite(ledVerde, HIGH);

    lcd.setCursor(0,0);
    lcd.print("Ambiente Esc.");

    lcd.setCursor(0,1);
    lcd.print("Luz:");
    lcd.print(mediaLuz);
  }

  else if(mediaLuz >= 300 && mediaLuz <= 800) {

    // Meia luz
    digitalWrite(ledAmarelo, HIGH);

    lcd.setCursor(0,0);
    lcd.print("Ambiente meia");

    lcd.setCursor(0,1);
    lcd.print("luz");
  }

  else {

    // Muito claro
    digitalWrite(ledVermelho, HIGH);

    digitalWrite(buzzer, HIGH);

    lcd.setCursor(0,0);
    lcd.print("Ambiente");

    lcd.setCursor(0,1);
    lcd.print("muito claro");
  }

  delay(2000);

  lcd.clear();

  if(mediaTemperatura >= 10 && mediaTemperatura <= 15) {

    lcd.setCursor(0,0);
    lcd.print("Temperatura OK");

    lcd.setCursor(0,1);
    lcd.print(mediaTemperatura,1);
    lcd.print(" C");
  }

  else if(mediaTemperatura > 15) {

    digitalWrite(ledAmarelo, HIGH);

    digitalWrite(buzzer, HIGH);

    lcd.setCursor(0,0);
    lcd.print("Temp. Alta");

    lcd.setCursor(0,1);
    lcd.print(mediaTemperatura,1);
    lcd.print(" C");
  }

  else {

    digitalWrite(ledAmarelo, HIGH);

    digitalWrite(buzzer, HIGH);

    lcd.setCursor(0,0);
    lcd.print("Temp. Baixa");

    lcd.setCursor(0,1);
    lcd.print(mediaTemperatura,1);
    lcd.print(" C");
  }

  delay(2000);

  lcd.clear();

  if(mediaUmidade >= 50 && mediaUmidade <= 70) {

    lcd.setCursor(0,0);
    lcd.print("Umidade OK");

    lcd.setCursor(0,1);
    lcd.print(mediaUmidade);
    lcd.print("%");
  }

  else if(mediaUmidade > 70) {

    digitalWrite(ledVermelho, HIGH);

    digitalWrite(buzzer, HIGH);

    lcd.setCursor(0,0);
    lcd.print("Umidade Alta");

    lcd.setCursor(0,1);
    lcd.print(mediaUmidade);
    lcd.print("%");
  }

  else {

    digitalWrite(ledVermelho, HIGH);

    digitalWrite(buzzer, HIGH);

    lcd.setCursor(0,0);
    lcd.print("Umidade Baixa");

    lcd.setCursor(0,1);
    lcd.print(mediaUmidade);
    lcd.print("%");
  }


  delay(1000);
}
