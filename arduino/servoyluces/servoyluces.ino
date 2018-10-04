/* Control Arduino Ethernet
 */

#include <SPI.h>
#include <Ethernet.h>
#include <Servo.h> 

Servo microservo; 
int pos = 0; 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //Direccion Fisica MAC
byte ip[] = { 192, 168, 18, 177 };                       // IP Local que usted debe configurar 
byte gateway[] = { 192, 168, 18, 100 };                   // Puerta de enlace
byte subnet[] = { 255, 255, 255, 0 };                  //Mascara de Sub Red
EthernetServer server(80);                             //Se usa el puerto 80 del servidor     
String readString;

void setup() {

  Serial.begin(9600);  // Inicializa el puerto serial 
   while (!Serial) {   // Espera a que el puerto serial sea conectado, Solo necesario para el Leonardo
    ; 
  }
  pinMode(2,OUTPUT);        // Se configura como salidas los puertos del 2 al 6
  pinMode(3,OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  microservo.attach(7);  // Se configura como Servo el Puerto 7
 
  Ethernet.begin(mac, ip, gateway, subnet); // Inicializa la conexion Ethernet y el servidor
  server.begin();
  Serial.print("El Servidor es: ");
  Serial.println(Ethernet.localIP());    // Imprime la direccion IP Local
}


void loop() {
  // Crea una conexion Cliente
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();
     
        //Lee caracter por caracter HTTP
        if (readString.length() < 100) {
          //Almacena los caracteres a un String
          readString += c;
          
         }

         // si el requerimiento HTTP fue finalizado
         if (c == '\n') {          
           Serial.println(readString); //Imprime en el monitor serial
     
           client.println("HTTP/1.1 200 OK");           //envia una nueva pagina en codigo HTML
           client.println("Content-Type: text/html");
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<TITLE>Proyecto Domotica</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<hr />");
           client.println("<H1>Prueba de Conexion Ethernet Encendido de dos leds</H1>");
           client.println("<br />");  
           client.println("<H2>Control on/off 2-6");
           client.println("<br />");  
           
           client.println("<a href=\"/?button2on\"\"> Encender Pin2</a> ");           // construye en la pagina cada uno de los botones
           client.println(" | | | ");
           client.println("<a href=\"/?button2off\"\"> Apagar Pin2</a><br /> ");   
           client.println("<br />");
           
           client.println("<br />"); 
           client.println("<a href=\"/?button3on\"\"> Encender Pin3</a> ");
           client.println(" | | | ");
           client.println("<a href=\"/?button3off\"\"> Apagar Pin3</a><br /> ");   
           client.println("<br />");
           
           client.println("<br />"); 
           client.println("<a href=\"/?button4on\"\"> Encender Pin4</a> ");
           client.println(" | | | ");
           client.println("<a href=\"/?button4off\"\"> Apagar Pin4</a><br /> ");   
           client.println("<br />");
           
           client.println("<br />");  
           client.println("<a href=\"/?button5on\"\"> Encender Pin5</a>");
           client.println(" | | | ");
           client.println("<a href=\"/?button5off\"\"> Apagar Pin5</a><br />");   
           client.println("<br />");
           
                      client.println("<p>by: Foti,Loza, Flores,Torres</p>");  
           client.println("<br />"); 
           client.println("</BODY>");
           client.println("</HTML>");
     
           delay(1);
           //detiene el cliente servidor
           client.stop();
           
           //control del arduino si un boton es presionado
                   
           if (readString.indexOf("?button2on") >0){
               digitalWrite(2, HIGH);
           }
           if (readString.indexOf("?button2off") >0){
               digitalWrite(2, LOW);
           }
           
           if (readString.indexOf("?button3on") >0){
               digitalWrite(3, HIGH);
           }
           if (readString.indexOf("?button3off") >0){
               digitalWrite(3, LOW);
           }
           
           
           if (readString.indexOf("?button4on") >0){
               digitalWrite(4, HIGH);
           }
           if (readString.indexOf("?button4off") >0){
               digitalWrite(4, LOW);
           }
           
            if (readString.indexOf("?button5on") >0){
               digitalWrite(5, HIGH);
           }
           if (readString.indexOf("?button5off") >0){
               digitalWrite(5, LOW);
           }
           
           
           if (readString.indexOf("?button6on") >0){
               digitalWrite(6, HIGH);
           }
           if (readString.indexOf("?button6off") >0){
               digitalWrite(6, LOW);
           }
           
           
           if (readString.indexOf("?left") >0){
                for(pos = 0; pos < 180; pos += 3)  // Giro de 0 a 180 grados 
                {                                  
                  microservo.write(pos);             
                  delay(15);                       // Espera 15 ms para que el servo llege a la posicion 
                } 
           }
           if (readString.indexOf("?right") >0){
                for(pos = 180; pos>=1; pos-=3)     //Giro de 180 a 0 grados 
                {                                
                  microservo.write(pos);              
                  delay(15);                       // Espera 15 ms para que el servo llege a la posicion 
                } 
           }
            // Limpia el String(Cadena de Caracteres para una nueva lectura
            readString="";  
           
         }
       }
    }
}
}
