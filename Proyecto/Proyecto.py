import random
import time
from datetime import datetime
import pyodbc

user='sa'
password='Proye1234'
database='Proyecto'
server='192.168.42.246'
driver='SQL Server'

con_string='UID=%s;PWD=%s;DATABASE=%s;SERVER=%s;driver=%s' % (user,password,database,server,driver)

j=0

while j<1:
    from time import localtime, asctime
    TIME=time.strftime('%d-%m-%Y %H:%M:%S', time.localtime())

    print(TIME)
    TEMPERATURA=round(random.uniform(0, 50), 1)
    HUMEDAD=round(random.uniform(20, 90), 1)
    CO=round(random.uniform(10, 1000), 1)
    G_COMB=round(random.uniform(100, 10000), 1)
    G_NAT=round(random.uniform(300, 10000), 1)
    OZONO=round(random.uniform(10, 1000), 1)
    NO2=round(random.uniform(0.05, 10), 1)
    H2=round(random.uniform(1, 1000), 1)
    SO2=round(random.uniform(0, 20), 1)
    PART=random.randint(0, 16000)

    sql = "INSERT INTO Mediciones (temperatura, humedad,co,gc,gn,o3,no2,h2,so2,cp,fecha) VALUES (?,?,?,?,?,?,?,?,?,?,?)"
    val = (TEMPERATURA,HUMEDAD,CO,G_COMB,G_NAT,OZONO,NO2,H2,SO2,PART,TIME)
    cnxn=pyodbc.connect(con_string)
    cursor=cnxn.cursor()
    cursor.execute(sql, val)
    cnxn.commit()
    print(" Temperatura: ",TEMPERATURA,"[º] \n","Humedad: ",HUMEDAD,"[%]\n","Monóxido de carbono (CO): ",CO,"[ppm]\n"
          ,"Gases Combustibles: ",G_COMB,"[ppm]\n","Gases Naturales: ",G_NAT,"[ppm]\n"
          ,"OZONO (O3): ",OZONO,"[ppb]\n","Dióxido de Nitrógeno: ",NO2,"[ppm]\n"
          ,"Hidrógeno (H2): ",H2,"[ppm]\n","Dióxido de Azufre: ",SO2,"[ppm]\n"
          ,"Cantidad de particulas: ",PART,"[pcs/0.01cf]\n")
    time.sleep(60)
