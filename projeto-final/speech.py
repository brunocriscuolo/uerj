import speech_recognition as sr

microphone = sr.Recognizer()
with sr.Microphone(device_index=0) as source:
    microphone.adjust_for_ambient_noise(source)
    print('Speak anything...\n')
    audio = microphone.listen(source)

    try:
        text = microphone.recognize_google(audio)
        print('You said: {}'.format(text))

    except:
        print('Sorry, could not recognize your voice.')
