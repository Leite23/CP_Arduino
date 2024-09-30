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

  if(valor<40) {
    digitalWrite(ledR, HIGH);
    digitalWrite(ledA, LOW);
    digitalWrite(ledV, LOW);
    tone(buzzer,300);
    delay(500);
    noTone(buzzer);
    delay(500);
    Serial.println("Alta luminosidade");
    delay(2000);
  } else {
    if(valor<80) {
      digitalWrite(ledR, LOW);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledV, LOW);
      Serial.println("Alerta de aumento de luminosidade");
      delay(2000);
    } else {
      if(valor>80) {
        digitalWrite(ledR, LOW);
        digitalWrite(ledA, LOW);
        digitalWrite(ledV, HIGH);
        Serial.println("Luminosiade ok");
        delay(2000);
      }
    }
  }
}
