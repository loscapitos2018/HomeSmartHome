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

#conexion al servidor DB

try:
    nx = mysql.connector.connect(user='root', password='12345678',
                              host='127.0.0.1',
                              database='luz')
    print("Conectado a la DB")
    cursor = nx.cursor()
    while True:
        n="select estado from luces"
        cursor.execute(n)
        p=(cursor.fetchone())
        #print(p)
        m=p[0]
        #print(m)
        
        arduino.write(m.encode())
        time.sleep (1)
        nx.close()
        
        nx = mysql.connector.connect(user='root', password='12345678',
                              host='127.0.0.1',
                              database='luz')
        cursor = nx.cursor()
        if m=="0":
            q="UPDATE `luces` SET `idluz`=1,`estado`=1 WHERE 1"
            cursor.execute(q)
            print("Paso a 1")
        else:    
            q="UPDATE `luces` SET `idluz`=1,`estado`=0 WHERE 1"
            cursor.execute(q)
            print("Paso a 0")
    

except mysql.connector.Error as err:
    if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
        print("Usuario o contraseña incorrecta")
    elif err.errno == errorcode.ER_BAD_DB_ERROR:
        print("Base de datos no existe")
    else:
        print(err)
else:
    nx.close()
     
