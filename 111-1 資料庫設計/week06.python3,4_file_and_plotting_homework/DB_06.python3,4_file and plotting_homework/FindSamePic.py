import os,hashlib
cur_path=os.path.dirname(__file__) # 取得目前路徑
sample_tree=os.walk(cur_path)

allmd5s = dict() 
n=0
for dirname,subdir,files in sample_tree:
   allfiles=[]   
   for file in files:  # 取得所有 .png .jpg 檔，存入 allfiles 串列中
      ext=file.split('.')[-1]
      if ext=="PNG" or ext=="jpg": 
         allfiles.append(dirname +'/'+file)       
         
   if len(allfiles)>0: 
      for imagefile in allfiles:
          img_md5 = hashlib.md5(open(imagefile,'rb').read()).digest()          
          if img_md5 in allmd5s:
              if n==0:
                  print("找到下列重覆的檔案：")
                  n+=1
              print(os.path.abspath(imagefile))
              print(allmd5s[img_md5] + "\n")
          else:
               allmd5s[img_md5] = os.path.abspath(imagefile) 
     
print("完成...")



