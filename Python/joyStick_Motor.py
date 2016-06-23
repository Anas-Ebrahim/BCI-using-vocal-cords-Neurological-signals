import RPi.GPIO as GPIO
import time

#################################################
# Warning off
#GPIO.setwarnings(False)

#################################################
# BCM numbering 
GPIO.setmode(GPIO.BCM)
# BOARD numbering 
#GPIO.setmode(GPIO.BOARD)

#################################################
#import joystick code
import Joystick_v3

#import MotorFunction code
import MotorFunction
#################################################
"""
# Choose Your Pins in motor

MotorFunction.FrDir=1 #forward  left
MotorFunction.FrPwm=5 #forward left PWM
 
MotorFunction.FlDir=6 #forward left
MotorFunction.FlPwm=13 #forward left PWM
 
MotorFunction.BrDir=8 #Backword right
MotorFunction.BrPwm=9 #Backword right PWM
 
MotorFunction.BlDir=10 #Backword left
MotorFunction.BlPwm=11 #Backword left PWM

#pwm DutyCycle

MotorFunction.FrDuty=85#forward right DutyCycle
MotorFunction.FlDuty=70#forward left DutyCycle
MotorFunction.BrDuty=100#Backword right DutyCycle
MotorFunction.BlDuty=70#Backword left DutyCycle

#pwm Frequency

MotorFunction.FrFrequency=1000
MotorFunction.FlFrequency=1000
MotorFunction.BrFrequency=1000
MotorFunction.BlFrequency=1000

#################################################
#joystick BCM pins do not change

Joystick_v3.J_Forward_Pin = 17
Joystick_v3.J_Back_Pin = 14
Joystick_v3.J_Right_Pin = 2
Joystick_v3.J_Left_Pin = 15 
Joystick_v3.J_RotateRight_Pin = 4
Joystick_v3.J_RotateLeftt_Pin = 3
#################################################
"""
#init motor and joystick pins

MotorFunction.MotorInit()
Joystick_v3.Joystick_Init()
try:
    while 1:
        PressedKey=Joystick_v3.Joystick_Read ()
        MotorFunction.Move(PressedKey)
        print PressedKey
        time.sleep(0.5)
        
except KeyboardInterrupt:
    pass
MotorFunction.PwmStop( MotorFunction.GlobalFrPwm )
MotorFunction.PwmStop( MotorFunction.GlobalFlPwm )
MotorFunction.PwmStop( MotorFunction.GlobalBrPwm )
MotorFunction.PwmStop( MotorFunction.GlobalBlPwm )
GPIO.cleanup() 
 
