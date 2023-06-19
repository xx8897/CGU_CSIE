import os.path
cur_path=os.path.dirname(__file__) # 取得目前路徑
print(cur_path)



sample_tree=os.walk(cur_path)
for dirname,subdir,files in sample_tree:
    print("檔案路徑：",dirname)
    print("目錄串列：" , subdir)   
    print("檔案串列：",files)
    print()


