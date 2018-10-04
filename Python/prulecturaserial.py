#!/usr/bin/python

# Importamos la libreira de PySerial
import serial

# Abrimos el puerto del arduino a 9600
locations=['COM5']  
for device in locations:    
    try:    
        print ("Conectado a Arduino en: ",device )
        arduino = serial.Serial('COM5', 9600,timeout=10)  
        break  
    except:    
        print ("Fallo la conexion a: ",device )


#PuertoSerie = serial.Serial('/dev/ttyACM0', 9600)
# Creamos un buble sin fin
while True:
  # leemos hasta que encontarmos el final de linea
  sArduino = arduino.readline()
  # Mostramos el valor leido y eliminamos el salto de linea del final
  print("Valor Arduino: ") + sArduino.rstrip('\n')
