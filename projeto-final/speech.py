#!/usr/bin/python
# -*- coding: utf-8 -*-
import speech_recognition as sr
from gtts import gTTS
import os
import sys

reload(sys)
sys.setdefaultencoding('utf-8')

def listen():
    microphone = sr.Recognizer()
    with sr.Microphone() as source:
        print('\nSpeak anything...\n')
        audio = microphone.listen(source)
        try:
            text = microphone.recognize_google(audio, language='pt-BR')
            print('You said: {}'.format(text))
        except Exception as e:
            print('Sorry, could not recognize your voice.')
            print(e)
    return text

def speak(txt):
    tts = gTTS(text=txt, lang='pt-br')
    tts.save('sound.mp3')
    os.system('mpg321 sound.mp3')

def recording(txt):
    file = open('output.txt', 'w')
    file.write(txt)
    file.close()

def format():
    with open("output.txt", "r") as fin:
        with open("prog.py", "w") as fout:
            for line in fin:
                fout.write(line.replace('se', 'if'))

phrase = listen()
speak(phrase)
recording(phrase)
format()
