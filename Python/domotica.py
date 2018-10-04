import serial
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

#conexion al servidor DB

try:
    nx = mysql.connector.connect(user='root', password='12345678',
                              host='127.0.0.1',
                              database='hsh')
    print("Conectado a la DB")
    cursor = nx.cursor()
    while True:
        n="select estado from luces"
        cursor.execute(n)
        p=(cursor.fetchone())
        print(p)
        m=p[0]
        print(m)
        
        arduino.write(m.encode())
        time.sleep (1)
        nx.close()
        
        nx = mysql.connector.connect(user='root', password='12345678',
                              host='127.0.0.1',
                              database='hsh')
        cursor = nx.cursor()
        if m=="0":
            q="UPDATE `luces` SET `id_cuarto`=1,`estado`=2 WHERE 1"
            cursor.execute(q)
            print("Azul")
        elif m=="2":
            q="UPDATE `luces` SET `id_cuarto`=1,`estado`=3 WHERE 1"
            cursor.execute(q)
            print("Verde")
        else:    
            q="UPDATE `luces` SET `id_cuarto`=1,`estado`=4 WHERE 1"
            cursor.execute(q)
            print("Rojo")
        nx = mysql.connector.connect(user='root', password='12345678',
                              host='127.0.0.1',
                              database='hsh')
        cursor = nx.cursor()


except mysql.connector.Error as err:
    if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
        print("Usuario o contraseña incorrecta")
    elif err.errno == errorcode.ER_BAD_DB_ERROR:
        print("Base de datos no existe")
    else:
        print(err)
else:
    nx.close()
     
