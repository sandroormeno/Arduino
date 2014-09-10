

int boton = 7;    // botón
int varTEM;          // variable temporal que lee el estado del botón
int botonStado;   // varieble que recuerda el estado del botón

void setup() {
  pinMode(boton, INPUT); // botón como input
  Serial.begin(9600);  // activa la comunicación serial a 9600bps
  botonStado = digitalRead(boton); // lee el estado incial del botón
}


void loop(){
  varTEM = digitalRead(boton); // lee el estado del botón
  if (varTEM != botonStado) {  // comprueba si el estado incial es diferente al estado actual
    if (varTEM == LOW) {   // comprueba si esta presionado
      Serial.println("Boton presionado");
    } else {     // de lo contrario el botón debe estar sin presionar
      Serial.println("Boton sin presionar");
    }
  }

  botonStado = varTEM;   // guarda el estado del botón para la siguiente comprobación
}
