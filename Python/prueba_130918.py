import serial
import adafruit_dht
import mysql.connector
import time
from mysql.connector import errorcode
import sys

locations=['COM5']  
for device in locations:    
    try:    
        print ("Conectado a Arduino en: ",device )
        arduino = serial.Serial('COM5', 9600,timeout=10)  
        break  
    except:    
        print ("Fallo la conexion a: ",device )

try:
    con = mysql.connector.connect(user='root', password='12345678',
                              host='127.0.0.1',
                              database='hsh') #conexion al servidor DB
    print("Conectado a la DB")
    cursor = con.cursor()#declaramos el cursor para la conexion
    while True: #bucle sin fin ...
        L1="select estado from luces" #cargamos en L1 los valores de estado de luces 
        P1="select estado from puerta" #cargamos en P1 los valores de estado puertas
        T1="select estado from temperatura" #cargamos en T1 los valores de estado temperatura
        cursor.execute(L1) #executamos el cursor L1
        L1n=(cursor.fetchone()) # tomamos el primer registro (one)
        #print(L1n)
        tupla1=L1n[0] #tomo el carater 1 de la tupla
        print(tupla1)
        arduino.write(tupla1.encode()) #envio a ARDUINO el valor de la tupla
        print(arduino.readline())
        T1=(arduino.readline())
        print(T1)
        time.sleep (0) # pauso el bucle xx segundos (solo para debug
        con.close() # cierro la conexion xq?
        
        con = mysql.connector.connect(user='root', password='12345678',
                              host='127.0.0.1',
                              database='hsh')#conexion al servidor DB
        cursor = con.cursor()
       # try:
        #if arduino.inWaiting() > 0:

        #except KeyboardInterrupt:
          #  print(" Parado manualmente")
          #  guardaT="UPDATE `temperatura` SET `id_cuarto`=1,`estado`= 1 WHERE 1"
           # break
except mysql.connector.Error as err: #manejo de errores en apertura de DB
    if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
        print("Usuario o contraseña incorrecta")
    elif err.errno == errorcode.ER_BAD_DB_ERROR:
        print("Base de datos no existe")
    else:
        print(err)
else:
    con.close() #cierro DB
