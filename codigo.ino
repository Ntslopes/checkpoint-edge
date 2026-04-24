int sensorPin = A5;
int ledPin1 = 10;
int ledPin2 = 9;
int ledPin3 = 8;
int buzzer = 7;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  int i = 0;
  //pegando o valor do ldr
  int valor_ldr = analogRead(sensorPin);
  //modificando o valor do ldr para 0 e 1023
  int ldr_modificado = map(valor_ldr, 207, 1012, 0, 1023);
  Serial.println(ldr_modificado);
  delay(500);

  //led verde
  if(ldr_modificado >=0 && ldr_modificado <300){
    digitalWrite(ledPin3, HIGH);
  }
  else{
  digitalWrite(ledPin3, LOW);
  };
  //led amarelo
  if(ldr_modificado >=300 && ldr_modificado <=800){
    digitalWrite(ledPin2, HIGH);
  }
  else{
  digitalWrite(ledPin2, LOW);
  };
  
  //led vermelho
if (ldr_modificado > 800 && ldr_modificado <= 1023) {

  //loop de 3 segundos para gerar a buzina em alta luminosidade
  for (int i = 0; i < 1; i++) {
    digitalWrite(buzzer, HIGH); 
    delay(3000); 
    digitalWrite(buzzer, LOW); 
    delay(500); 
    digitalWrite(ledPin1, HIGH); 
  }
} 
else {
  digitalWrite(ledPin1, LOW);
  digitalWrite(buzzer, LOW); 
}

delay(100);
}

