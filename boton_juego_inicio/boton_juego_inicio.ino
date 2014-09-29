int boton = 5;
int varTEM;  
int botonStado;   

void setup() {
  pinMode(boton, INPUT); 
  botonStado = LOW; 
  Serial.begin(9600);  
  Serial.println("Este es mi boton inicio.... ");
}
void loop(){
  varTEM = digitalRead(boton); 
  if (varTEM != botonStado) {  
    if (varTEM  == LOW) {   
      Serial.print("Boton = ");
      Serial.println(boton);
    } 
    botonStado = varTEM;
  }
}























