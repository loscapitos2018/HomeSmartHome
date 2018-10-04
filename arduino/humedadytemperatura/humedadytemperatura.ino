#include <DHT.h>
#define DHTPIN 7     // Indicamos el pin donde conectaremos la patilla data de nuestro sensor

// Descomenta el tipo de sensor que vas a emplear. En este caso usamos el DHT11
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Conecta el pin 1 (el de la izquierda) del sensor a +5V
// Conecta el pin 2 del sensor al pin que has elegido para DHTPIN
// Conecta el pin 4 (el de la derecha) del sensor a GROUND

DHT dht11(DHTPIN, DHTTYPE);  // indicamos en que pin esta conectado el data, y el tipo de sensor

String sResultado, sEspacios;
int iContador;
int iTamanoCadena = 4;

void setup() 
{
  //Inicio comunicacion serie para ver los datos en el ordenador
  Serial.begin(9600); 
  //Iniciamos el sensor
  dht11.begin();
}

void loop() 
{
  int iHumedad = dht11.readHumidity();  //Guarda la lectura de la humedad
  int iTemperatura = dht11.readTemperature();  //Guarda la lectura de la temperatura

  // Comprobamos si lo que devuelve el sensor es valido, si no son numeros algo esta fallando
  if (isnan(iHumedad) || isnan(iTemperatura)) // funcion que comprueba si son numeros las variables indicadas 
  {
    Serial.println("Fallo al leer del sensor DHT 11"); //Mostramos mensaje de fallo si no son numeros
  } 
  else 
  {
    // añadimos la humedad y la temperatura, añadiendo al final de cada uno el caracter "|" 
    sResultado = String(iHumedad) + "|" + String(iTemperatura) + "|";
    sEspacios = "";
    // Calculamos cuantos espacios tenemos que crear
    // Le restamos 3 que es el tamaño del campo final
    if (sResultado.length() < (iTamanoCadena - 3))
    {      
      // Creamos la cadena
      for (iContador = 0; iContador < ((iTamanoCadena - 3) - sResultado.length()); iContador ++)
      {
        // le añadimos el caracter que queramos, no vale para nada
        sEspacios += "X";
      }
    }
    // Añadimos el campo de fin de registro
    sResultado = sResultado + sEspacios + "|f|";
    // lo enviamos al puerto serie
    Serial.println(sResultado);
  }
  // y esperamos 1 segundo para volver a leer los datos del sensor.
  delay(1000);
}
