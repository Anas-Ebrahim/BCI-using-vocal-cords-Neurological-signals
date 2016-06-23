import uinput
import RPi.GPIO as GPIO

forward = 17
back = 14
right = 2
left = 15 
RotateR = 4
RotateL = 3

def Joystick_Init ():

	GPIO.setmode(GPIO.BOARD)

	GPIO.setup(forward, GPIO.IN)
	GPIO.setup(back, GPIO.IN)
	GPIO.setup(right, GPIO.IN)
	GPIO.setup(left, GPIO.IN)
	GPIO.setup(RotateR, GPIO.IN)
	GPIO.setup(RotateL, GPIO.IN)
        return 

def Joystick_Read ():
	F = 'FWD'
	B = 'BCK'
	R = 'RG'
	L = 'LF'
	RR = 'ROTR'
	RL = 'ROTL'
	FR = 'FWD-R'
	FL = 'FWD-L'
	BR = 'BCK-R'
	BL = 'BCK-L'
	S = 'STOP'
	
	FwdIp=GPIO.input(forward)
	BkIp =GPIO.input(back)
	RgIp =GPIO.input(right)
	LfIp =GPIO.input(left)
	RotRIp=GPIO.input(RotateR)
	RotLIp=GPIO.input(RotateL)


	if FwdIp==True  AND LfIp==True AND RotRIp==False AND RotLIp==False: 
	#forward and left is pressed
	ReturnVal = FL

	elif FwdIp==True  AND RgIp==True AND RotRIp==False AND RotLIp==False: 
	#forward and right is pressed
	ReturnVal = FR
	
	elif BkIp==True  AND RgIp==True AND RotRIp==False AND RotLIp==False: 
	#back and right is pressed
	ReturnVal = BR
	
	elif BkIp==True  AND LfIp==True AND RotRIp==False AND RotLIp==False:
	#back and left is pressed
	ReturnVal = BL

	elif FwdIp==True AND RotRIp==False AND RotLIp==False: 
	#forward is pressed
	ReturnVal = F
	
	elif BkIp==True AND RotRIp==False AND RotLIp==False:
	#back is pressed
	ReturnVal = B
	
	elif RgIp==True AND RotRIp==False AND RotLIp==False:
	#right is pressed
	ReturnVal = R
	
	elif LfIp==True AND RotRIp==False AND RotLIp==False:
	#left is pressed
	ReturnVal = L
	
	elif RotRIp==True AND RotLIp==False:
	#rotate right is pressed
	ReturnVal = RR
	
	elif RotLIp==True AND RotRIp==False:
	#rotate left is pressed
	ReturnVal = RL
	
	else:
	#stop is pressed
	ReturnVal = S
	
	return ReturnVal
