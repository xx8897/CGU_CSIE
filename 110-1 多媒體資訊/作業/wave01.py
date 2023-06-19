import wave
from scipy import *
from pylab import *
filename = 'Nello.wav'
wavefile = wave.open(filename,'rb') # open for writing

nchannels = wavefile.getnchannels()
sample_width = wavefile.getsampwidth()
framerate = wavefile.getframerate()
numframes = wavefile.getnframes()
comptype = wavefile.getcomptype()
str_data = wavefile.readframes(numframes)

print(nchannels)
print(sample_width)
print(framerate)
print(numframes)
wavefile.close()

path = 'copy.wav'

copyfile=wave.open(path,'wb')
copyfile.setnchannels(nchannels)
copyfile.setsampwidth(sample_width)
copyfile.setframerate(framerate)
copyfile.setnframes(numframes)
copyfile.writeframesraw(str_data)
copyfile.close()

copyfile=wave.open(path,'rb')
print(copyfile.getparams())
copyfile.close()

