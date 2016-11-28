#################################################
# import thread
import sys
import urllib2
from PyQt4.QtCore import QThread
#################################################
# import Qt
from PyQt4 import QtCore
from PyQt4 import QtGui
from PyQt4 import uic
import RPi.GPIO as GPIO
import RPi.GPIO as GPIO
import time
#################################################
# Warning off
GPIO.setwarnings(False)
#################################################
# BCM numbering 
GPIO.setmode(GPIO.BCM)
# BOARD numbering 
#GPIO.setmode(GPIO.BOARD)

#################################################
# dont change

Pressed=True
Realesed=False
#################################################
# qt paramter
qtCreatorFile = "WheelChair_V9.ui" # Enter file here.

Ui_MainWindow,QtBaseClass = uic.loadUiType(qtCreatorFile)
#################################################
#import joystick code
import Joystick_v3

#import MotorFunction code
import MotorFunction
#################################################
PressedKey=''
JoyyStick=Realesed
GUI_Flag=Realesed
#################################################
# thread code,pirioty to TuochScreen
class JoyStickThread(QtCore.QThread):
    
    def __init__(self):
        QThread.__init__(self)

    def run(self):
        try: 
            while True:
                # call global joyystick 
                global JoyyStick
                global GUI_Flag
                global PressedKey
                PressedKey=Joystick_v3.Joystick_Read ()
                JoyyStick=Realesed
                if PressedKey !='Stop':
                        MotorFunction.Move(PressedKey)
                        JoyyStick=Pressed
                        #print PressedKey
                elif PressedKey =='Stop' and GUI_Flag == Realesed :
                        MotorFunction.Move(PressedKey)
                        #print PressedKey
                time.sleep(0)        
        except KeyboardInterrupt:
            pass
        
#################################################
class MyApp(QtGui.QMainWindow, Ui_MainWindow):
    # when pressed on button ,attach every button with name
    def __init__(self):
        QtGui.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)
        self.Forward.pressed.connect(self.ForwardButton)
        self.Back.pressed.connect(self.BackButton)
        self.Right.pressed.connect(self.RightButton)
        self.Left.pressed.connect(self.LeftButton)
        self.Forward_Left.pressed.connect(self.Forward_LeftButton)
        self.Back_Left.pressed.connect(self.Back_LeftButton)
        self.Back_Right.pressed.connect(self.Back_RightButton)
        self.Forward_Right.pressed.connect(self.Forward_RightButton)
        self.RotateRight.pressed.connect(self.RotateRightButton)
        self.RotateLeft.pressed.connect(self.RotateLeftButton)
       
    # when Released button ,attach every button to one function 
        self.Forward.released.connect(self.StopButton )
        self.Back.released.connect(self.StopButton )
        self.Right.released.connect(self.StopButton )
        self.Left.released.connect(self.StopButton )
        self.Forward_Left.released.connect(self.StopButton )
        self.Back_Left.released.connect(self.StopButton )
        self.Back_Right.released.connect(self.StopButton )
        self.Forward_Right.released.connect(self.StopButton )
        self.RotateRight.released.connect(self.StopButton )
        self.RotateLeft.released.connect(self.StopButton )
    

    def  StopButton(self):
         if JoyyStick==Realesed:
             global GUI_Flag
             GUI_Flag=Realesed
             MotorFunction.Move('Stop')
             #print(" StopButton")

    def  ForwardButton(self):
         if JoyyStick==Realesed:  
             global GUI_Flag
             GUI_Flag=Pressed
             MotorFunction.Move('Forward')
             #print(" ForwardButton")
    
    def  BackButton(self):
        if JoyyStick==Realesed:  
            global GUI_Flag
            GUI_Flag=Pressed
            MotorFunction.Move('Back')
            #print(" BackButton")
    
    def  RightButton(self):
        if JoyyStick==Realesed: 
            global GUI_Flag
            GUI_Flag=Pressed
            MotorFunction.Move('Right')
            #print(" RightButton")
    
    def  LeftButton(self):
        if JoyyStick==Realesed:
            global GUI_Flag
            GUI_Flag=Pressed
            MotorFunction.Move('Left' )
            #print("LeftButton ")
    
    def  Forward_LeftButton(self):
        if JoyyStick==Realesed:  
            global GUI_Flag
            GUI_Flag=Pressed
            MotorFunction.Move( 'Forward_Left')
            #print(" Forward_LeftButton")

    def  Forward_RightButton(self):
        if JoyyStick==Realesed:  
            global GUI_Flag
            GUI_Flag=Pressed
            MotorFunction.Move('Forward_Right' )
            #print(" Forward_RightButton")
        
    def  Back_LeftButton(self):
        if JoyyStick==Realesed:  
            global GUI_Flag
            GUI_Flag=Pressed
            MotorFunction.Move('Back_Left' )
            #print(" Back_LeftButton")
    
    def  Back_RightButton(self):
        if JoyyStick==Realesed:  
            global GUI_Flag
            GUI_Flag=Pressed
            MotorFunction.Move('Back_Right' )
            #print(" Back_RightButton")
    
    def RotateRightButton (self):
        if JoyyStick==Realesed:  
            global GUI_Flag
            GUI_Flag=Pressed
            MotorFunction.Move('Rotate_Right' )
            #print(" RotateRightButton")
    
    def  RotateLeftButton(self):
        if JoyyStick==Realesed:  
            global GUI_Flag
            GUI_Flag=Pressed
            MotorFunction.Move('Rotate_Left' )
            #print(" RotateLeftButton")
    
#################################################    
if __name__ == "__main__":
    
#init motor and joystick pins
    MotorFunction.MotorInit()
    Joystick_v3.Joystick_Init()
#################################################    
#Qt code start
    app = QtGui.QApplication(sys.argv)
    window = MyApp()
    window.show()
#################################################    
#Thread code start
    threads = []
    JoyStcikObject = JoyStickThread()
    threads.append(JoyStcikObject)
    JoyStcikObject.start()
    
    sys.exit(app.exec_())   
#################################################    
#init motor and joystick pins
MotorFunction.PwmStop( MotorFunction.GlobalFrPwm )
MotorFunction.PwmStop( MotorFunction.GlobalFlPwm )
MotorFunction.PwmStop( MotorFunction.GlobalBrPwm )
MotorFunction.PwmStop( MotorFunction.GlobalBlPwm )
GPIO.cleanup() 
