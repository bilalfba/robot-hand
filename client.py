from socket import *
import sys
import serial

# Create a TCP/IP socket
sock = socket(AF_INET, SOCK_DGRAM)
#Change the text in parenthesis and replace with Port number
#Ex: for Windows: 'COM0'
#Ex: for Mac: '/dev/cu.usbmodem1421'
ser = serial.Serial('/dev/cu.usbmodem1421', 115200)

# Connect the socket to the port on the server given by the caller
SERVER_IP = '192.168.137.1'
# Use Any port number above 4000
port = 9987
#Use IP Adress of laptop connected to Glove (NOT THIS MACHINE)
server_address = ('192.168.137.1', port )

try:
    #This is the first message just to initialize the connection
    msg = 'Hello'
    sock.sendto(msg.encode('utf-8'), (SERVER_IP, port))
    while True : 
        (data,addr) = sock.recvfrom(1024)
        data = data.replace('\r\n' , '/')
        print(data)
        ser.write(data)


except KeyboardInterrupt:
    sock.close()
    ser.close()

finally:
    sock.close() 
    ser.close()
