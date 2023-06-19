import os
import matplotlib.pyplot as plt

cur = os.path.dirname("./")
tree = os.walk(cur)
freq = dict()
for dirname, subdir, files in tree:
    for file in files:
        with open(file, 'r', encoding='utf-8') as f :
            lines = f.readlines()
            for line in lines:
                words = line.split()
                for word in words:
                    if word in freq:
                        freq[word] += 1
                    else:
                        freq[word] = 0
result = sorted(freq.items(), key=lambda x:x[1], reverse = True)
y = [i[1] for i in result][0:9]
x = [i[0] for i in result][0:9]

plt.bar(x, y, color='red', label = "詞頻")
plt.show()