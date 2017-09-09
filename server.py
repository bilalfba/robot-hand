from socket import *
import sys
import serial
import time

# Create a TCP/IP socket
sock = socket(AF_INET, SOCK_DGRAM)
#Put your Own COM PORT below
ser = serial.Serial('COM8', 115200)
#Port number should be same as port number on client
PORT_NUMBER = 9987

sock.bind((gethostbyname('0.0.0.0'), PORT_NUMBER))


# Connect the socket to the port on the server given by the caller

try:
    (data, addr) = sock.recvfrom(1024)
    print(data)
    while True:
        i=0
        wdata = ''
        while i<4:
            data = ser.readline()
            wdata = wdata + data
            i=i+1
        print(wdata)
        sock.sendto(wdata.encode('utf-8'),addr)
except KeyboardInterrupt:
        sock.close()
        ser.close()
finally:
    sock.close()
    ser.close()
