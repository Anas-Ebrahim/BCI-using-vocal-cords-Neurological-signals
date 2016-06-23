import RPi.GPIO as GPIO
import time



#joystick BCM pins do not 

J_Forward_Pin = 17
J_Back_Pin = 14
J_Right_Pin = 2
J_Left_Pin = 15 
J_RotateRight_Pin = 4
J_RotateLeftt_Pin = 3
"""
#board joystick pins do not 
J_Forward_Pin = 11
J_Back_Pin = 8
J_Right_Pin = 3
J_Left_Pin = 10 
J_RotateRight_Pin = 7
J_RotateLeftt_Pin = 5
"""
def Joystick_Init ():
    GPIO.setmode(GPIO.BCM)
    
    # Warning off
    GPIO.setwarnings(False)
    #################################################

    GPIO.setup(J_Forward_Pin, GPIO.IN)
    GPIO.setup(J_Back_Pin, GPIO.IN)
    GPIO.setup(J_Right_Pin, GPIO.IN)
    GPIO.setup(J_Left_Pin, GPIO.IN)
    GPIO.setup(J_RotateRight_Pin, GPIO.IN)
    GPIO.setup(J_RotateLeftt_Pin, GPIO.IN)
    return 

def Joystick_Read ():
    F = 'Forward'
    B = 'Back'
    R = 'Right'
    L = 'Left'
    RR = 'Rotate_Right'
    RL = 'Rotate_Left'
    FR = 'Forward_Right'
    FL = 'Forward_Left'
    BR = 'Back_Right'
    BL = 'Back_Left'
    S = 'Stop'
    
    ReturnVal=''
	
    FwdIp=not GPIO.input(J_Forward_Pin)
    BkIp =not GPIO.input(J_Back_Pin)
    RgIp =not GPIO.input(J_Right_Pin)
    LfIp =not GPIO.input(J_Left_Pin)
    RotRIp=not GPIO.input(J_RotateRight_Pin)
    RotLIp=not GPIO.input(J_RotateLeftt_Pin)


    if FwdIp==True  and LfIp==True and RotRIp==False and RotLIp==False: 
    #J_Forward_Pin and J_Left_Pin is pressed
        ReturnVal = FL

    elif FwdIp==True  and RgIp==True and RotRIp==False and RotLIp==False: 
    #J_Forward_Pin and J_Right_Pin is pressed
        ReturnVal = FR
    
    elif BkIp==True  and RgIp==True and RotRIp==False and RotLIp==False: 
    #J_Back_Pin and J_Right_Pin is pressed
        ReturnVal = BR
    
    elif BkIp==True  and LfIp==True and RotRIp==False and RotLIp==False:
    #J_Back_Pin and J_Left_Pin is pressed
        ReturnVal = BL

    elif FwdIp==True and RotRIp==False and RotLIp==False: 
    #J_Forward_Pin is pressed
        ReturnVal = F
    
    elif BkIp==True and RotRIp==False and RotLIp==False:
    #J_Back_Pin is pressed
        ReturnVal = B
    
    elif RgIp==True and RotRIp==False and RotLIp==False:
    #J_Right_Pin is pressed
        ReturnVal = R
    
    elif LfIp==True and RotRIp==False and RotLIp==False:
    #J_Left_Pin is pressed
        ReturnVal = L
    
    elif RotRIp==True and RotLIp==False and FwdIp==False and BkIp==False and RgIp==False and LfIp==False:
    #rotate J_Right_Pin is pressed
        ReturnVal = RR
    
    elif RotLIp==True and RotRIp==False and FwdIp==False and BkIp==False and RgIp==False and LfIp==False:
    #rotate J_Left_Pin is pressed
        ReturnVal = RL
    
    else:
    #stop is pressed
        ReturnVal = S
    
    return ReturnVal


Joystick_Init ()
while True:
    Command=Joystick_Read ()
    if Command!='Stop':
        print Command
    time.sleep(0.5)
