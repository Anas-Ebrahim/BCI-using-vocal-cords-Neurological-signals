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
#######################PWM##########################
#  Frequency PWM function
def PwmFrequency (Pin,Frequency):  
  return GPIO.PWM( Pin   ,  Frequency )

#  DutyCyclePWM function
def PwmDutyCycle(DutyCycle,GlobalVar):   
  GlobalVar.ChangeDutyCycle(DutyCycle)
  return

#  PwmStart function
def PwmStart(GlobalVar ):   
  GlobalVar.start(0)
  return
 
#  PwmStop function
def PwmStop(GlobalVar):   
  GlobalVar.stop()
  return
#################################################

GlobalPwmred = PwmFrequency(red,1000)
GlobalPwmyellow = PwmFrequency(yellow ,1000)
GlobalPwmgreen = PwmFrequency(green ,1000)


PwmStart(GlobalPwmred )  
PwmStart(GlobalPwmyellow  )  
PwmStart(GlobalPwmgreen  )  
try:
    while 1:
        for DutyCycl_1 in range(0, 101, 5):
            PwmDutyCycle(DutyCycl_1,GlobalPwmred)
            PwmDutyCycle(DutyCycl_1,GlobalPwmyellow )
            PwmDutyCycle(DutyCycl_1,GlobalPwmgreen )
            time.sleep(0.1)
        for DutyCycl_1 in range(100, -1, -5):
            PwmDutyCycle(DutyCycl_1,GlobalPwmred)
            PwmDutyCycle(DutyCycl_1,GlobalPwmyellow )
            PwmDutyCycle(DutyCycl_1,GlobalPwmgreen )
            time.sleep(0.1)
except KeyboardInterrupt:
    pass
PwmStop(GlobalPwmred)
PwmStop(GlobalPwmyellow )
PwmStop(GlobalPwmgreen )
GPIO.cleanup()





