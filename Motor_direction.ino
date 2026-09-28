// C++ code
//
// Pines PWM para Motores
const int motorIzq1 = 5;  
const int motorIzq2 = 6;  
const int motorDer1 = 9;  
const int motorDer2 = 10;  

// Pines botones
const int btnIzquierda = 7;
const int btnDerecha   = 4;
const int btnDireccion = 3;// Controla el sentido de los motores
const int btnOff = 2;

// Variables la direccion
bool marchatras = false; // false = Adelante true = Atras
int ultimoEstadoBtnDir = HIGH; // Ultimo estado del boton

//Variable para el boton de apagado del sistema
int ultimoEstadoBtnOff = HIGH; 

// Variable para el on/off del sistema
bool sistemaActivo = false; 

void setup() {
  // Configurar pines de motores como salidas
  pinMode(motorIzq1, OUTPUT);
  pinMode(motorIzq2, OUTPUT);
  pinMode(motorDer1, OUTPUT);
  pinMode(motorDer2, OUTPUT);
  
  // Asegurar que los motores esten en OFF del inicio
  digitalWrite(motorIzq1, LOW);
  digitalWrite(motorIzq2, LOW);
  digitalWrite(motorDer1, LOW);
  digitalWrite(motorDer2, LOW);
  
  // Configurar botones con INPUTPULLUP
  pinMode(btnIzquierda, INPUT_PULLUP);
  pinMode(btnDerecha, INPUT_PULLUP);
  pinMode(btnDireccion, INPUT_PULLUP);
  pinMode(btnOff, INPUT_PULLUP);
}

void loop() {
  // Lectura del boton de direccion
  int estadoBtnDir = digitalRead(btnDireccion);
  
  // Detectar pulsación
  if (estadoBtnDir == LOW && ultimoEstadoBtnDir == HIGH) {
    if (!sistemaActivo) {
      sistemaActivo = true; // Una pulsación prende los motores
    } else {
      marchatras = !marchatras; //! Si ya estaba activo, cambia la dirección
    }
    delay(150); // Delay para Antibouncing
  }
  ultimoEstadoBtnDir = estadoBtnDir; 

  // Si el sistema NO está activo detiene el loop
  if (!sistemaActivo) {
    analogWrite(motorIzq1, 0); analogWrite(motorIzq2, 0);
    analogWrite(motorDer1, 0); analogWrite(motorDer2, 0);
    delay(20);
    return; // Cerrar el loop
  }

  // todo lo de abajo solo se ejecuta si el sistema está activo

  // Lectura del boton de giro
  int estadoIzquierda = digitalRead(btnIzquierda);
  int estadoDerecha   = digitalRead(btnDerecha);

  // Condicional: Avanza hacia adelante
  if (!marchatras) {
    // Avance al frente
    if (estadoIzquierda == HIGH && estadoDerecha == HIGH) {
      analogWrite(motorIzq1, 255); analogWrite(motorIzq2, 0);
      analogWrite(motorDer1, 255); analogWrite(motorDer2, 0);
    }
    // Giro abierto izq MIENTRAS SE MANTENGA PRESIONADO
    else if (estadoIzquierda == LOW) {
      analogWrite(motorIzq1, 100); analogWrite(motorIzq2, 0);
      analogWrite(motorDer1, 255); analogWrite(motorDer2, 0);
    }
    // Giro abierto der MIENTRAS SE MANTENGA PRESIONADO
    else if (estadoDerecha == LOW) {
      analogWrite(motorIzq1, 255); analogWrite(motorIzq2, 0);
      analogWrite(motorDer1, 100); analogWrite(motorDer2, 0);
    }
  }

  // Condicional: Reversa
  else {
    // Retrocede
    if (estadoIzquierda == HIGH && estadoDerecha == HIGH) {
      analogWrite(motorIzq1, 0); analogWrite(motorIzq2, 255);
      analogWrite(motorDer1, 0); analogWrite(motorDer2, 255);
    }
    // Giro abierto izq MIENTRAS SE MANTENGA PRESIONADO
    else if (estadoIzquierda == LOW) {
      analogWrite(motorIzq1, 0); analogWrite(motorIzq2, 100);
      analogWrite(motorDer1, 0); analogWrite(motorDer2, 255);
    }
    // Giro abierto der MIENTRAS SE MANTENGA PRESIONADO
    else if (estadoDerecha == LOW) {
      analogWrite(motorIzq1, 0); analogWrite(motorIzq2, 255);
      analogWrite(motorDer1, 0); analogWrite(motorDer2, 100);
    }
  }
  
  // Condicional: Apagar el circuito
  int estadoBtnOff = digitalRead(btnOff);
  if (estadoBtnOff == LOW && ultimoEstadoBtnOff == HIGH){
    sistemaActivo = false;
    return;
	}
  
  delay(20); //Delay para la simulación
}
