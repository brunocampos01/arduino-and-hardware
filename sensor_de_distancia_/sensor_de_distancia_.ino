const int trigPin = 12;
const int echoPin = 8;

void setup() {
  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);  // define o pino triger como saída.   
  pinMode(echoPin, INPUT); // define o pino echo como entrada.   
}

void loop () {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); //não envia o som e espera o retorno do som enviado
  unsigned long duracao = pulseIn(echoPin, HIGH);  //Captura a duração em tempo do retorno do som.
  int distancia = duracao/56;
  Serial.print("Distancia em CM: ");
  Serial.println(distancia);
  delay(500);
}

