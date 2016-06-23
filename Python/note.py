FrDuty=50#forward right DutyCycle
FlDuty=50#forward left DutyCycle
BrDuty=50#Backword right DutyCycle
BlDuty=50#Backword left DutyCycle

FrDir=29 #forward  left
FlDir=32 #forward left
BrDir=35 #Backword right
BlDir=37 #Backword left

ForwardDir=True
ReverseDir=False
Stop=0

GlobalFrPwm = PwmFrequency( FrPwm ,1000)
GlobalFlPwm = PwmFrequency( FlPwm ,1000)
GlobalBrPwm = PwmFrequency( BrPwm ,1000)
GlobalBlPwm = PwmFrequency( BlPwm ,1000)



