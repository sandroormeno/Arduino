//TMP36 
int sensor_de_temperarura = A0; 

void setup()
{
  Serial.begin(9600);  
}

void loop()                    
{
  int lectura = analogRead(sensor_de_temperarura);  
  float voltage = lectura * 5.0; //5.0 es el voltage que trabaja en arduino.
  
  //float permite valores de 32 bits
  //Números de 3.4028235E+38 a -3.4028235E+38
  //3.4028235E+38 = 3.4028235 x 10 a la 38 = 3532.130793
  //6 decimales de precisión.
  
  
  
  voltage /= 1024.0; //esto es igual a voltage = voltage / 1024.0
  float temperatura = (voltage - 0.5) * 100 ;  
  Serial.print(temperatura); 
  Serial.println(" Grados centigrados");
  delay(1000);                                    
}


