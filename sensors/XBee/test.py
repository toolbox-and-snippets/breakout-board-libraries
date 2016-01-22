from xbee import XBee
import serial
import time
ser = serial.Serial('/dev/ttyUSB0', 19200)

xbee = XBee(ser)

# Continuously read and print packets
while True:
    try:
	time.sleep(0.01)
        response = xbee.wait_read_frame()
        print response
	print hi
	print '\n'
    except KeyboardInterrupt:
        break
        
ser.close()
