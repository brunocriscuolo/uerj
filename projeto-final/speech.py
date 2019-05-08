import speech_recognition as sr
from gtts import gTTS
import os

def listen():
    microphone = sr.Recognizer()
    with sr.Microphone() as source:
        print('Speak anything...\n')
        audio = microphone.listen(source)
        try:
            text = microphone.recognize_google(audio)
            print('You said: {}'.format(text))
        except:
            print('Sorry, could not recognize your voice.')
    return text

def speak(audio):
    tts = gTTS(text=audio, lang='en')
    tts.save('sound.mp3')
    #print("I'm learning what you said...")
    os.system("mpg321 sound.mp3")

phrase = listen()
speak(phrase)
