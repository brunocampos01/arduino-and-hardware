#include <Servo.h>
#include <AFMotor.h>

AF_DCMotor motor1(3);    // Define o motor1 ligado ao M3  
AF_DCMotor motor2(4);    // Define o motor2 ligado ao M4  

const int trigPin = 12;
const int echoPin = 13;

void setup(){    
   Serial.begin(9600); // inicializa a comunicação serial para mostrar dados   
     
   //configurações do servos motores 
   motor1.setSpeed(255);       // Define a velocidade para os motores 1.A velocidade máxima é 255  
   motor2.setSpeed(255);       // Define a velocidade para os motores 2. A velocidade máxima é 255

  //config do sensor de distacia
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// Função principal do Arduino    
  void loop(){
   medir_distacia();    
   andar();   
  }    
    
  // Função para chamar outras funções e definir o que o robô fará  
void andar(){      
   Serial.print("distancia: "); // Exibe no serial       
     rotacao_Frente();
     rotacao_Parado();
     rotacao_Direita();
     rotacao_Frente();  
}  
  
  
  // Função para fazer o carro parar    
  void rotacao_Parado()    
  {    
   Serial.println(" Parar ");  
   motor1.run(RELEASE); // Motor para  
   motor2.run(RELEASE);
   delay(1000);  
  }
  
  // Função para fazer o robô andar para frente    
  void rotacao_Frente()    
  {    
   Serial.println(" frente ");   
   motor1.run(FORWARD); // Roda vai para frente  
   motor2.run(FORWARD); // Roda vai para frente 
   delay(5000); 
  }    
  
    // Função que faz o robô virar à direita    
  void rotacao_Direita()    
  {    
   Serial.println(" Para a direita ");  
   motor1.run(FORWARD); // Roda vai para frente  
   motor2.run(BACKWARD); // Roda vai para trás   
   delay(500);    
  }  
  
    // Função que faz o robô virar à esquerda    
  void rotacao_Esquerda()    
  {    
   Serial.println(" Para a esquerda ");  
   motor1.run(BACKWARD); // Roda vai para trás  
   motor2.run(FORWARD); // Roda vai para frente  
   delay(1000);    
  }   
  
   
  // Função que faz o robô andar para trás e emite som quando ele dá ré    
  void rotacao_Re()    
  {    
   Serial.println(" ré ");  
   motor1.run(BACKWARD);    // Roda vai para trás  
   motor2.run(BACKWARD);    // Roda vai para trás  
   rotacao_Parado();    
  }  

  void medir_distacia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned long duracao = pulseIn(echoPin, HIGH);
  int distancia = duracao / 58;
  Serial.print("Distancai em CM: ");
  Serial.println(distancia);
  delay(1000);
  }


