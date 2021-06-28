import time
from gtts import gTTS

from pygame import mixer

mixer.init()



k = gTTS(text= f'The Date is  {time.asctime(time.localtime(time.time()))}' ,lang = "en" ,slow=False)
k.save('./../date.mp3')
mixer.music.load('./../date.mp3')

mixer.music.play()

while(True):
    input()
    mixer.music.stop()






