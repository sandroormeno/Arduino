//TMP36 con voltaje de referencia
//http://arduino.cc/en/Reference/AnalogReference
int sensor_de_temperarura = A5; 

#define voltaje_aref 4.5 //se define el voltaje de referencia
//note que usa #define y no es necesario finalizar con unto y coma (;)

void setup()
{
  Serial.begin(9600);
  analogReference(EXTERNAL); //Conecte el 5V a AREF (21) 
}

void loop()                    
{
  int lectura = analogRead(sensor_de_temperarura);  
  float voltage = lectura * voltaje_aref; //Uso del voltaje de referencia. 
  voltage /= 1024.0; //esto es igual a voltage = voltage / 1024.0
  float temperatura = (voltage - 0.5) * 100 ;  
  Serial.print(temperatura); 
  Serial.println(" C");
  delay(1000);                                    
}
