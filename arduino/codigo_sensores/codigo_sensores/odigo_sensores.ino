// Sistema Simple de Monitoreo del Agua
// UNAD 2024

#define TRIG_PIN 5
#define ECHO_PIN 18
#define TURBIDEZ_PIN 34

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("Sistema iniciado");
}

void loop() {
  float nivel = leerNivel();
  float turbidez = leerTurbidez();
  
  Serial.print("Nivel: ");
  Serial.print(nivel);
  Serial.print(" cm | Turbidez: ");
  Serial.println(turbidez);
  
  delay(5000);
}

float leerNivel() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duracion = pulseIn(ECHO_PIN, HIGH);
  float distancia = duracion * 0.034 / 2;
  return 200 - distancia;
}

float leerTurbidez() {
  int valor = analogRead(TURBIDEZ_PIN);
  float voltaje = valor * (3.3 / 4095.0);
  return voltaje * 100;
}