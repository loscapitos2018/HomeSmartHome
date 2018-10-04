///INCLUIMOS LIBRERIAS NECESARIAS
#include <DHT.h>
#include <DHT_U.h>
#include <Servo.h>

///DEFINICIONES
#define DHTPIN 7     // Indicamos el pin donde conectaremos la patilla data de nuestro sensor
#define DHTTYPE DHT11   // Seleccionamos el tipo de sensor DHT 11 

DHT dht11(DHTPIN, DHTTYPE);  // indicamos en que pin esta conectado el data, y el tipo de sensor
Servo servo; //Creamos un objeto Servo de nombre... servo

// Conecta el pin 1 del sensor a +5V
// Conecta el pin 2 del sensor al pin que 7 para DHTPIN
// Conecta el pin 3 del sensor a GROUND

///VARIABLES A UTILIZAR

String sResultado, sEspacios;
int iContador;
int iTamanoCadena = 4;
int val = 0; //Variable de entrada del Serial
int pin=4;

void setup(){
  Serial.begin(9600);
  // Iniciamos los pines de luces
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(7,INPUT);
  dht11.begin();//Iniciamos el sensor de temperatura
  servo.attach(9); //Conectamos el servo al pin digital 9 
}
void loop(){
  if(Serial.available()!=0){
      int iHumedad = dht11.readHumidity();  //Guarda la lectura de la humedad
      int iTemperatura = dht11.readTemperature();  //Guarda la lectura de la temperatura

       // Comprobamos si lo que devuelve el sensor es valido, si no son numeros algo esta fallando
      if (isnan(iHumedad) || isnan(iTemperatura)){ // funcion que comprueba si son numeros las variables indicadas 
          Serial.println("Fallo al leer del sensor DHT 11"); //Mostramos mensaje de fallo si no son numeros
          } 
      else {
      // añadimos la humedad y la temperatura, añadiendo al final de cada uno el caracter "|" 
          sResultado = String(iHumedad) + "@" + String(iTemperatura) + "@";
          sEspacios = "";
      // Calculamos cuantos espacios tenemos que crear
      // Le restamos 3 que es el tamaño del campo final
      if (sResultado.length() < (iTamanoCadena - 3)) {
      // Creamos la cadena
         for (iContador = 0; iContador < ((iTamanoCadena - 3) - sResultado.length()); iContador ++){
      // le añadimos el caracter que queramos, no vale para nada
         sEspacios += "X";
       }
      }
      // Añadimos el campo de fin de registro
      //   sResultado = sResultado + sEspacios + "|f|";
      // lo enviamos al puerto serie
         Serial.println(sResultado);
      }
      // y esperamos 1 segundo para volver a leer los datos del sensor.
      //delay(1000);
      switch(Serial.read()){
///////
      case '2':digitalWrite(13,LOW), digitalWrite(12,HIGH),digitalWrite(11,LOW);
              break;
      case '3':digitalWrite(13,HIGH), digitalWrite(12,LOW),digitalWrite(11,LOW);
              break;
      case '4':digitalWrite(13,LOW), digitalWrite(12,LOW),digitalWrite(11,HIGH);
              break;
      case '5':digitalWrite(13,LOW), digitalWrite(12,LOW),digitalWrite(11,LOW);
              break;
      }
     if(Serial.available() > 0) //Detecta si hay alguna entrada por serial
   {
      val = Serial.parseInt();
      if(val != 0)
      {
      
         servo.write(val); //Mueve el servo a la posición entrada (excepto si es 0)
      }
   }
   delay(500);
  }
}
