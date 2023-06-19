import wave
from scipy import *
from pylab import *

filename = 'Nello.wav'
wavefile = wave.open(filename,'rb') # open for writing
#讀取wav檔案的四種資訊的函式。其中numframes表示一共讀取了幾個frames
params = wavefile.getparams()
str_data = wavefile.readframes(params.nframes)
print(wavefile.getparams())
wavefile.close()

path = 'copy01.wav'
copyfile=wave.open(path,'wb')
copyfile.setparams(params)
copyfile.writeframesraw(str_data)
copyfile.close()

copyfile=wave.open(path,'rb')
print(copyfile.getparams())
copyfile.close()

