///INCLUIMOS LIBRERIAS NECESARIAS
#include <DHT.h>
#include <DHT_U.h>
#include <Servo.h>

///DEFINICIONES
#define DHTPIN 7     // Indicamos el pin donde conectaremos la patilla data de nuestro sensor
#define DHTTYPE DHT11   // Seleccionamos el tipo de sensor DHT 11 
Servo servo; //Creamos un objeto Servo de nombre... servo
DHT dht11(DHTPIN, DHTTYPE);  // indicamos en que pin esta conectado el data, y el tipo de sensor


// Conecta el pin 1 del sensor a +5V
// Conecta el pin 2 del sensor al pin que 7 para DHTPIN
// Conecta el pin 3 del sensor a GROUND

///VARIABLES A UTILIZAR

String sResultado, sEspacios;
int iContador;
int iTamanoCadena = 4;
int val = 0; //Variable de entrada del Serial
int pin=4;
int vTemp;
int vHum;

void setup(){
  Serial.begin(9600);
  // Iniciamos los pines de luces
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(3,OUTPUT);  
  pinMode(9,INPUT);
  pinMode(7,INPUT);
  dht11.begin();//Iniciamos el sensor de temperatura
  servo.attach(9); //Conectamos el servo al pin digital 9 
}
void loop(){
      int iHumedad = dht11.readHumidity();  //Guarda la lectura de la humedad
      int iTemperatura = dht11.readTemperature();  //Guarda la lectura de la temperatura
      if (vTemp != iTemperatura){
         Serial.println("Temperatura" + String(iTemperatura)+ "°" ); 
         Serial.println(vTemp);        
         vTemp = iTemperatura;
      if (vTemp >= 24){
          digitalWrite(3,HIGH);
         }
         else {
          digitalWrite(3,LOW);
         }
         }
        
      if (vHum != iHumedad){
         Serial.println("Humedad" + String(iHumedad)+ "%" );
         Serial.println(vHum);
         vHum = iHumedad;
         }
     if(Serial.available()) //Detecta si hay alguna entrada por serial
   {

      switch(Serial.read()){
      case 'V':digitalWrite(13,LOW), digitalWrite(12,HIGH),digitalWrite(11,LOW);
              break;
      case 'A':digitalWrite(13,HIGH), digitalWrite(12,LOW),digitalWrite(11,LOW);
              break;
      case 'R':digitalWrite(13,LOW), digitalWrite(12,LOW),digitalWrite(11,HIGH);
              break;
      case 'P':digitalWrite(13,LOW), digitalWrite(12,LOW),digitalWrite(11,LOW);
              break;
      }

      val = Serial.parseInt();
      if(val != 0)
      {
         servo.write(val); //Mueve el servo a la posición entrada (excepto si es 0)
      }
   }
}
