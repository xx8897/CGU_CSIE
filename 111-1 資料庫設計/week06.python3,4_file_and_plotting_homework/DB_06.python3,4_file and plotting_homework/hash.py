import hashlib

m = hashlib.md5()
data = "Hello world"
# 先將資料編碼，再更新 MD5 雜湊值
m.update(data.encode("utf-8"))
h = m.hexdigest()
print(h)


data = "Hello world!"
# 先將資料編碼，再更新 MD5 雜湊值
m.update(data.encode("utf-8"))
h = m.hexdigest()
print(h)



