
from gtts import gTTS
import os
from pygame import mixer

mixer.init()

try:

    mytxt = open( f'{os.getcwd()}\\mytext\\mytext.txt',"r")



    print("Press Any key to Stop and Exit and hit the Enter button\n")
    k = gTTS(text= f'{mytxt.read()}' ,lang = "en" ,slow=False)
    k.save('./../date.mp3')
    mixer.music.load('./../date.mp3')

    mixer.music.play()

    while(True):
        input()
        mixer.music.stop()
        break
except SyntaxError:
    print("Please check Your Internet Connection or Python Installation \nPress any key to Exit")


exit()


