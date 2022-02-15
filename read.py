import serial
from datetime import datetime
import csv
import sys

ser = serial.Serial('COM3', baudrate=115200)
ser.flushInput()
ser.setDTR(True)

print("Writing...")


while True:
    try:
        
        ser_bytes = ser.readline()
        if ser_bytes == None:
            sys.exit(0)
        decode_b = ser_bytes[0:len(ser_bytes)-1].decode('utf-8')
        
        with open("test.txt", 'a', newline='') as f:
            writer = csv.writer(f, delimiter=",")
            writer.writerow([decode_b])
    except KeyboardInterrupt:
        ser.close()
        sys.exit(0)



#   create a vector of vector of dataype int (int matrix)
#   create a file stream to read the file in std::ios::in
#   set a string line
#   set a delimiter, so that we can know when to break the string
#   create a vector of vector of type string to store the read values from csv
#   while(file with line variable):
#       create a string stream and a cell with string type.
#       create row vector of type string 
#           while(line stream, cell variable and the delimiter):
#               push data to row
#           push row to vector of vector of type string
#   #conversion and return the final data
#   for(size of string matrix):
#       create vector of type int as a temp vector
#       for(size of first row of string matrix):
#           push value to temp after converting the value with stoi()
#       push the temp row to final int matrix
#   return int matrix