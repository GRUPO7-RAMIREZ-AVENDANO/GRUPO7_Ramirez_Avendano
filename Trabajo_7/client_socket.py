import socket

HEADER = 64
PORT = 3074
SERVER = '192.168.42.246'
ADDR = (SERVER, PORT)
FORMAT = 'utf-8'
DISCONNECT_MESSAGE = 'DISCONNECT!'

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect(ADDR)

def send(msg):
    message=msg.encode(FORMAT)

    msg_length = len(message)
    send_length = str(msg_length).encode(FORMAT)

    send_length += b' '*(HEADER-len(send_length))

    client.send(send_length)
    client.send(message)
    print(client.recv(2048).decode(FORMAT))

import re, uuid
send((':'.join(re.findall('..', '%012x' % uuid.getnode()))) )
send('Hello')
send('Test')
print(f"Escriba mensaje para ser enviado: ")
msj = input()
send(msj)
input()
send(DISCONNECT_MESSAGE)
