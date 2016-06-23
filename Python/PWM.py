import RPi.GPIO as GPIO
import time
# BOARD numbering 
GPIO.setmode(GPIO.BOARD)

# Warning off
GPIO.setwarnings(False)

# Choose Your Pins
yellow=11
red=13
green=15

# Sets up pins 
GPIO.setup(red, GPIO.OUT)
GPIO.setup( yellow, GPIO.OUT)
GPIO.setup( green, GPIO.OUT)


p = GPIO.PWM(red , 1000)  # channel=13 frequency=1000Hz
p.start(0)
try:
    while 1:
        for DutyCycle in range(0, 101, 5):
            p.ChangeDutyCycle(DutyCycle)
            time.sleep(0.1)
        for DutyCycle in range(100, -1, -5):
            p.ChangeDutyCycle(DutyCycle)
            time.sleep(0.1)
except KeyboardInterrupt:
    pass
p.stop()
GPIO.cleanup()
