import time
#import RPi.GPIO as GPIO
from RPi import GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(21,GPIO.OUT)

try:
    while True:
        GPIO.output(21,GPIO.HIGH)
        time.sleep(1)
        print("On")
        
        GPIO.output(21,GPIO.LOW)
        time.sleep(1)
        print("Off")
        
except KeyboardInterrupt:
    pass
finally:
  GPIO.cleanup()