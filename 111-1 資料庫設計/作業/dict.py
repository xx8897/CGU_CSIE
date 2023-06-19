dictionary = dict()
with open('dict_a.txt', 'r', encoding="utf-8") as f:
    lines = f.readlines()
    for line in lines:
        try:
            dictionary[line.split(",")[0]] = line.split('"')[1]
        except:
            try:
                dictionary[line.split(",")[0]] = line.split(",")[3]
            except:
                pass
while True:
    print(dictionary[input()])