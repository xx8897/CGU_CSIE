from scipy.io.wavfile import read

# 讀取 WAV 檔案
rate, data = read("Nello3.wav")

# 取樣頻率
print("Sample rate: {} Hz".format(rate))
print("Data type: {}".format(data.dtype))

import matplotlib.pyplot as plt

# 繪製前 1024 點資料的波形圖
plt.figure(figsize=(15, 5))
plt.plot(data[0:1024])
plt.show()