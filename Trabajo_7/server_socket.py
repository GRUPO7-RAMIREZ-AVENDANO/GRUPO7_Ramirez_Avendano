import socket
import threading

HEADER = 64
PORT = 3074
SERVER = '192.168.42.246'
ADDR = (SERVER, PORT)
FORMAT = 'utf-8'
DISCONNECT_MESSAGE = 'DISCONNECT!'
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind(ADDR)

def handle_client(conn, addr):
    print(f"[NEW CONNECTION] {addr} connected.")
    first = 1
    connected = True
    while connected:
        msg_length = conn.recv(HEADER).decode(FORMAT)
        if msg_length:
            msg_length = int(msg_length)
            msg = conn.recv(msg_length).decode(FORMAT)
            if msg == DISCONNECT_MESSAGE:
                connected = False
            if first == 1:
                print(f"[{addr}] Estas recibiendo una conexión de la siguiente MAC ADDRESS: {msg} Autorizar? SI/NO")
                auth = input()
                first = 0
                if auth == 'SI':
                    print(f"Cliente Autorizado")
                    conn.send("Cliente Autorizado".encode(FORMAT))
                else:
                    print(f"Cliente no permitido")
                    conn.send("Cliete no permitido".encode(FORMAT))
                    connected = False
            else:
                print(f"[{addr}] {msg}")
                conn.send("Mensaje Recibido".encode(FORMAT))

    conn.close()


def start():
    server.listen()
    print(f"[LISTEN] Server is listening on address {ADDR}")
    while True:
        conn, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()
        print(f"[ACTIVE CONNECTIONS] {threading.activeCount() - 1}")

print("[STARTING] server is running.....")
start()
