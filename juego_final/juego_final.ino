// Protitipo de Juego de Memoria para mis alumnos de DI de la PUCP


//Entradas digitales para los botones
int boton[] = {
  10,11,12};
//variable temporal
int varTEM;
//arreglo con el estado de los botones, 
//el valor de la variable temporar se guarda en este arreglo
int botonStado[] = {
  0,0,0};   // varieble que recuerda el estado del botón

// arreglo con las frecuencias de los botones
int sonidos[] = {
  1047, 1109, 1175};
//salida de buzzer
int pinsonido = 8;

int juego[] = {
  0,0,0,0,0,0};

int pasos = 1;
int btn;
int tiempo = 500;


void setup() {
  for(int i=0;i<3;i++){
    pinMode(boton[i], INPUT); 
    botonStado[i] = LOW;
  }
  Serial.begin(9600);  // activa la comunicación serial a 9600bps
  Serial.println("Buen inicio de juego");
  randomSeed(analogRead(0));
}


void loop(){ 
  switch (pasos) {
  case 1:
    Serial.println("Inicio de reconocimiento de botones");
    Serial.println("Preciona boton 1");
    pasos++;
    break;
  case 2:
    for(int i=0;i<3;i++){
      botones(i,0);
    } 
    break;
  case 3:
    delay(300);
    noTone(pinsonido);
    Serial.println("Preciona boton 2");
    pasos++;
    break;
  case 4:
    for(int i=0;i<3;i++){
      botones(i,1);
    } 
    break;
  case 5:
    delay(300);
    noTone(pinsonido);
    Serial.println("Preciona boton 3");
    pasos++;
    break;
  case 6:
    for(int i=0;i<3;i++){
      botones(i,2);
    } 
    break;
  case 7:
    delay(300);
    noTone(pinsonido);
    Serial.println("Reconocimiento de botones terminado");
    pasos++;
    break;
  case 8:
    for(int i=0;i<3;i++){
      juego[i] = random(30)/10;
    }
    pasos++;
    break;

  case 9:
    Serial.println("Escuche atentamente esta secuencia...");
    delay(1000);
    for(int i=0;i<3;i++){   
      tone(pinsonido, sonidos[juego[i]]);
      delay(tiempo);
      noTone(pinsonido);
      delay(tiempo/5);
    }
    pasos++;
    break;
  case 10:
    Serial.println("Ahora reproduzca la secuencia...");
    pasos++;
    break;   
  case 11:
    delay(300);
    noTone(pinsonido);
    for(int i=0;i<3;i++){
      botones(i,juego[0]);
    } 
    break;
  case 12:
    delay(300);
    noTone(pinsonido);
    for(int i=0;i<3;i++){
      botones(i,juego[1]);
    } 
    break;
  case 13:
    delay(300);
    noTone(pinsonido);
    for(int i=0;i<3;i++){
      botones(i,juego[2]);
    } 
    break;
  case 14:
    delay(300);
    noTone(pinsonido);
    Serial.println("Bien, nuevamente... pero mas rapido");
    tiempo -= 10;
    pasos = 8;
    break;
  default:
  
    break;
  }
}

//Funcion que detecta el estado del boton
// i es el indice para el arreglo de botones, estado de boton y sonidos

void botones(int i, int target){
  varTEM = digitalRead(boton[i]); // lee el estado del botón
  if (varTEM != botonStado[i]) {  // comprueba si el estado incial es diferente al estado actual
    if (varTEM  == LOW) {   // comprueba si esta presionado
      //Serial.println(mensaje);
      //Serial.println(boton[i]);
      btn = i;
      if (btn == target){
        Serial.println("Bien, boton reconocido!");
        pasos++;
      }
      else{
        Serial.println("Malo, intenta nuevamente!");
      }
      tone(pinsonido, sonidos[i]);
    }
    else{
      noTone(pinsonido);
    }
    botonStado[i] = varTEM;
  }
}































