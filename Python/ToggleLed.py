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


# make PIns on or off
#while True:
#  GPIO.output( red, not GPIO.input( red))
#  time.sleep(1)
#  GPIO.output( red,  0)
#  time.sleep(1)
GPIO.output( red, 0)
GPIO.output( yellow, 0)
GPIO.output(green , 0)

