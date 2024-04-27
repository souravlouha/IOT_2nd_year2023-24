//PWM
//'''
//Control the Brightness of LED using PWM on Raspberry Pi
//'''

import RPi.GPIO as GPIO
from time import sleep

ledpin = 17             # PWM pin connected to LED
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)       #set pin numbering system
GPIO.setup(ledpin,GPIO.OUT)
pi_pwm = GPIO.PWM(ledpin,50)      #create PWM instance with frequency of 50 Hertz
pi_pwm.start(0)             #start PWM of required Duty Cycle 
while True:
    for duty in range(100):
        pi_pwm.ChangeDutyCycle(duty) #provide duty cycle in the range 0-100
        sleep(0.02)
    sleep(1)
    
    for duty in range(100):
        pi_pwm.ChangeDutyCycle(100-duty)
        sleep(0.02)
    sleep(1)