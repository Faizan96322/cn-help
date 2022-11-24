import socket

def server_program():
    host = socket.gethostname()
    port = 5000

    server_socket = socket.socket()
    server_socket.bind((host, port))

    server_socket.listen(3)
    conn, addr = server_socket.accept()
    print("connection from: " + str(addr))
    
    while True:
        data = conn.recv(1024).decode()
        if not data:
            break
        doc = open("./" + data, 'r')
        data = doc.read(1024)
        conn.send(data.encode())

    conn.close()

if __name__ == '__main__':
    server_program()