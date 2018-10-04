#include <DHT11.h>
#include <Ethernet.h>
#include <SPI.h>


// Configuracion del Ethernet Shield
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFF, 0xEE}; // Direccion MAC
byte ip[] = {192,168,0,110};
byte server[] = {192,168,0,108};
EthernetClient client; 
int pin=7;
DHT11 dht11(pin);

//int analog_pin = 0;

void setup(void) {
   Serial.begin(115200);
  Ethernet.begin(mac, ip); // Inicializamos el Ethernet Shield
  delay(1000); // Esperamos 1 segundo de cortesia
}

void loop(void) {
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(DHT11_RETRY_DELAY); //delay for reread

  //Display in Serial Monitor
 // Serial.print(temp); //Return temperature to Monitor
//  Serial.println(" oC");
 // Serial.print(humi); //Return temperature to Monitor
//  Serial.println(" H");

  // Proceso de envio de muestras al servidor
  Serial.println("Connecting...");
  if (client.connect(server, 90)>0) {  // Conexion con el servidor
    client.print("GET ");
    client.print("/tutorial/iot.php?temp="); // Enviamos los datos por GET
    client.print(temp);
    Serial.print(temp);
    client.print("GET ");
    client.print("/tutorial/iot2.php?humi="); // Enviamos los datos por GET
    client.print(humi);
    Serial.print(humi);

    client.println(" HTTP/1.0");
    client.println("User-Agent: Arduino 1.0");
    client.println();
    Serial.println("Conectado");
  } else {
    Serial.println("Fallo en la conexion");
  }
  if (!client.connected()) {
    Serial.println("Disconnected!");
  }
  client.stop();
  client.flush();
  delay(5000); // Espero un minuto antes de tomar otra muestra
}
