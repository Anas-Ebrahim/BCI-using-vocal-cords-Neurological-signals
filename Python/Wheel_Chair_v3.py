import pyaudio 
import speech_recognition as sr


while True:
    # obtain audio from the microphone
    Recognition_Object= sr.Recognizer()
    with sr.Microphone(device_index=2, sample_rate=44100, chunk_size=512) as source:

        print("I'm waiting for your command !")
        audio = Recognition_Object.listen(source)
        print "Thank you, Now processing !"
        
# recognize speech using Google Speech Recognition
    try:
       Command=Recognition_Object.recognize_google(audio,language= "ar-EG")
       # print("Google Speech Recognition thinks you said " + Command)
       if Command=="امشي".decode("utf8"):
           print("The Chair is moving Forward")
           
       elif Command=="ارجع".decode("utf8"):
           print("The Chair is moving Backward")
       elif Command=="شمال".decode("utf8"):
           print("The Chair is moving Left")
       elif (Command=="يمين".decode("utf8")) or (Command=="لمين".decode("utf8")) or (Command=="جنين".decode("utf8")) or (Command=="يميل".decode("utf8"))or(Command=="ايميل".decode("utf8"))or(Command=="جميل".decode("utf8"))or(Command=="مين".decode("utf8")):
           print("The Chair is moving Right")
       elif (Command=="بس".decode("utf8")):
           print("The Chair is stopped")
       else:
           print("Sorry, Could you repeat again please !")
           
    except sr.UnknownValueError:
        print("Sorry, Could you repeat again please !")
    except sr.RequestError as e:
        #print("Could not request results from Google Speech Recognition service; {0}".format(e))
        print("Check the Internet connection please !")
        print("Error description: ".format(e))

