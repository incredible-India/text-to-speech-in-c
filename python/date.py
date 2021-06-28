import time
from gtts import gTTS

from pygame import mixer

mixer.init()

try:

    print("Press Any key to Stop and Exit and hit the Enter button\n")
    k = gTTS(text= f'The Date is  {time.asctime(time.localtime(time.time()))}' ,lang = "en" ,slow=False)
    k.save('./../date.mp3')
    mixer.music.load('./../date.mp3')

    mixer.music.play()

    while(True):
        input()
        mixer.music.stop()
        break
except Exception as errorMessage:
    print("Please check Your Internet Connection or Python Installation \nPress any key to Exit")


exit()


