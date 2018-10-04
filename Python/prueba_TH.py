import serial
import adafruit_dht



locations=['COM5']  
for device in locations:    
    try:    
        print ("Conectado a Arduino en: ",device )
        arduino = serial.Serial('COM5', 9600,timeout=10)  
        break  
    except:    
        print ("Fallo la conexion a: ",device )
#from board import ()
dht_device = adafruit_dht . DHT11(4)
temperature = dht_device . temperature
humidity = dht_device . humidity
