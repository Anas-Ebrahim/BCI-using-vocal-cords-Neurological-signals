import RPi.GPIO as GPIO
import time
# BOARD numbering 
GPIO.setmode(GPIO.BOARD)

# Warning off
GPIO.setwarnings(False)
#################################################
#dont change
ForwardDir=True
ReverseDir=False
Stop=0
#################################################
# Choose Your Pins

FrDir=29 #forward  left
FrPwm=31 #forward left PWM
 
FlDir=32 #forward left
FlPwm=33 #forward left PWM
 
BrDir=35 #Backword right
BrPwm=36 #Backword right PWM
 
BlDir=37 #Backword left
BlPwm=38 #Backword left PWM

#pwm DutyCycle

FrDuty=85#forward right DutyCycle
FlDuty=70#forward left DutyCycle
BrDuty=100#Backword right DutyCycle
BlDuty=70#Backword left DutyCycle

#pwm Frequency

FrFrequency=1000
FlFrequency=1000
BrFrequency=1000
BlFrequency=1000

#Name of Strings
ForwardRight =''
ForwardLeft  =''
BackwordRight=''
BackwordLeft =''
#################################################
# Must Pwm Pins intialize first

GPIO.setup(FrPwm , GPIO.OUT)
GPIO.setup(FlPwm , GPIO.OUT)
GPIO.setup(BrPwm , GPIO.OUT)
GPIO.setup(BlPwm , GPIO.OUT)
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
#  Motors function

def MotorInit():
  GPIO.setup(FrDir , GPIO.OUT)
  GPIO.setup(FlDir , GPIO.OUT)
  GPIO.setup(BrDir , GPIO.OUT)
  GPIO.setup(BlDir , GPIO.OUT)
  return

def MotorWrite(WhichMotor,Dir,DutyCycle):
 if WhichMotor=="fr":
     GPIO.output( FrDir ,  Dir )
     PwmDutyCycle(DutyCycle ,GlobalFrPwm )
 elif WhichMotor=="fl":
     GPIO.output( FlDir ,  Dir )
     PwmDutyCycle(DutyCycle ,GlobalFlPwm )
 elif WhichMotor=="br":
     GPIO.output( FrDir ,  Dir )
     PwmDutyCycle(DutyCycle ,GlobalBrPwm )
 elif WhichMotor=="bl":
     GPIO.output( FrDir ,  Dir )
     PwmDutyCycle(DutyCycle ,GlobalBlPwm )
 else:
     MotorStop()
 return

def MotorForward():
 MotorWrite("fr",ForwardDir,FrDuty)
 MotorWrite("fl",ForwardDir,FlDuty )
 MotorWrite("br",ForwardDir,BrDuty )
 MotorWrite("bl",ForwardDir,BlDuty )
    
 return

def MotorReverse():

 MotorWrite("fr", ReverseDir,FrDuty )
 MotorWrite("fl", ReverseDir,FlDuty )
 MotorWrite("br", ReverseDir,BrDuty )
 MotorWrite("bl", ReverseDir,BlDuty )
          
 return

def MotorRight():
 MotorWrite("fr",ReverseDir,FrDuty )
 MotorWrite("fl",ForwardDir,FlDuty )
 MotorWrite("br",ReverseDir,BrDuty )
 MotorWrite("bl",ForwardDir,BlDuty )
 
 return

def MotorLeft():

 MotorWrite("fr", ForwardDir,FrDuty )
 MotorWrite("fl", ReverseDir,FlDuty )
 MotorWrite("br", ReverseDir,BrDuty )
 MotorWrite("bl", ForwardDir,BlDuty )
 
 return

def MotorStop():
 PwmDutyCycle( Stop ,GlobalFrPwm )
 PwmDutyCycle( Stop ,GlobalFlPwm )           
 PwmDutyCycle( Stop ,GlobalBrPwm )           
 PwmDutyCycle( Stop ,GlobalBlPwm )           
 
 return

#################################################
#pwm Frequency
GlobalFrPwm = PwmFrequency( FrPwm ,FrFrequency)
GlobalFlPwm = PwmFrequency( FlPwm ,FlFrequency )
GlobalBrPwm = PwmFrequency( BrPwm ,BrFrequency )
GlobalBlPwm = PwmFrequency( BlPwm ,BlFrequency )
#Start pwm 
PwmStart(GlobalFrPwm  )  
PwmStart(GlobalFlPwm  )  
PwmStart(GlobalBrPwm  )  
PwmStart(GlobalBlPwm  )  
#################################################
MotorInit()
try:
    while 1:
        MotorForward()
        time.sleep(0.1)
except KeyboardInterrupt:
    pass
PwmStop( GlobalFrPwm)
PwmStop( GlobalFlPwm )
PwmStop( GlobalBrPwm )
PwmStop( GlobalBlPwm )
GPIO.cleanup() 
 
