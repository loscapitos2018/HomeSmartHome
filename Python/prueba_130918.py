import serial
import mysql.connector
import time
from mysql.connector import errorcode
import sys

locations=['COM5']  
for device in locations:    
    try:    
        print ("Conectado a Arduino en: ",device )
        arduino = serial.Serial('COM5', 9600)  
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
        L1="select estado from luces" #cargamos en L1 los valores de estado 
        P1="select estado from puerta" #cargamos en P1 los valores de estado
        T1="select estado from temperatura" #cargamos en T1 los valores de estado
        cursor.execute(L1) #executamos el cursor L1
        L1n=(cursor.fetchone()) # tomamos el primer registro (one)
        tupla1=L1n[0] #tomo el carater 1 de la tupla
        arduino.write(m.encode()) #envio a ARDUINO el valor de la tupla
        time.sleep (0) # pauso el bucle xx segundos (solo para debug
        con.close() # cierro la conexion xq?
        
        con = mysql.connector.connect(user='root', password='12345678',
                              host='127.0.0.1',
                              database='hsh')#conexion al servidor DB
        cursor = con.cursor()
except mysql.connector.Error as err: #manejo de errores en apertura de DB
    if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
        print("Usuario o contraseña incorrecta")
    elif err.errno == errorcode.ER_BAD_DB_ERROR:
        print("Base de datos no existe")
    else:
        print(err)
else:
    con.close() #cierro DB
