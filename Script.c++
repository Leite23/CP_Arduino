int ledV = 12;
int ledA = 11;
int ledR = 10;
int buzzer = 13;
int valorLido = 0;
int valor = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledR, OUTPUT);
}

void loop() {
  int valorLido = analogRead(A0);
  valor = map(valorLido, 0, 1023, 0, 100);
  delay(100);
  Serial.println(valor);

  if(valor<15) {
    digitalWrite(ledR, HIGH);
    digitalWrite(ledA, LOW);
    digitalWrite(ledV, LOW);
    Serial.println("Alta luminosidade");
    delay(500);
  } else {
    if(valor<30) {
      digitalWrite(ledR, LOW);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledV, LOW);
      tone(buzzer,500, 3000);
      delay(3000);
      noTone(buzzer);
      delay(500);
      Serial.println("Alerta de aumento de luminosidade");
      delay(500);
    } else {
      if(valor>30) {
        digitalWrite(ledR, LOW);
        digitalWrite(ledA, LOW);
        digitalWrite(ledV, HIGH);
        Serial.println("Luminosiade ok");
        delay(500);
      }
    }
  }
}
