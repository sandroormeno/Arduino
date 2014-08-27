/*
Uso de bucle for:
1. Tiene 3 parámetros que van entre paréntesis ().
2. En el primer parámetro se declara una variable: int j = 0.
3. El segundo parámetro es una condición: j < 100. 
   El bucle se ejecutará cuando la condición sea verdad
4. El último parámetro incrementa la variable: j++. 
   En este caso incrementa en 1.

for( int j = 0; j<100; j++)
 {
  //usar la variable
 }
 
*/
int led = 13;
void setup() {                  
  pinMode(led, OUTPUT);     
}

void loop() {
  
  //Usaremos el bucle for para hacer que el led se encienda 
  //en un PRIMER intervalo de 100 milisegundos 
  //y se incremente hasta llegar a un segundo.
  
  int t = 300;
  digitalWrite(led, HIGH);   
  delay(t);               
  digitalWrite(led, LOW);    
  delay(t); 

}



