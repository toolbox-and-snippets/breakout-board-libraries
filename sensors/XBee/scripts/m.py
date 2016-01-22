
from xbee import XBee

import serial

ser = serial.Serial('/dev/ttyUSB0', 19200)


xb = XBee(ser)


# Continuously read and print packets
while True:

    try:
        response = xb.wait_read_frame()

        print response
    except KeyboardInterrupt:

        break
        
ser.close()


