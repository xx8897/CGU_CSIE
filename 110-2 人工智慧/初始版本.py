#!/usr/bin/env python
# coding: utf-8

# In[12]:


import time

import os


# In[13]:


g = {}  # 存放父子節點
statusl = []# 表示方式[ML, CL, MR, CR, B]  左傳教士、左食人族、右傳教士、右食人族、船
route = []  # 一次路徑
way = []  # 總路徑
actions = [[1, 0], [0, 1], [1, 1], [0, 2], [2, 0], [3, 0], [0, 3], [2, 1] ]  #操作方式


# In[14]:


def result(s):
    if s[0] < 0 or s[1] < 0 or s[2] < 0 or s[3] < 0:  # 負數
        return
    if (s[0] < s[1] and s[0] != 0) or (s[2] < s[3] and s[2] != 0):  # 傳教士被吃
        return
    d = tuple(s)    #元组作为狀態点
    if len(statusl) > 1:
        f = tuple(statusl[-2][:])
        if f in g.keys() and d not in g[f]:
            g[f].append(d)
        else:
            g[f] = [d]

    for k in statusl[:-1]:   #重複狀態
        if k[0] == s[0] and k[1] == s[1] and k[3] == s[3] and k[4] == s[4]:
            return

    mid = [0] * 5
    for j in actions:
        mid[0] = s[0] - j[0] * s[4]
        mid[1] = s[1] - j[1] * s[4]
        mid[2] = s[2] + j[0] * s[4]
        mid[3] = s[3] + j[1] * s[4]
        mid[4] = -s[4]
        statusl.append(mid[:])
        result(mid)   #判斷該動作是否合理，並加入字典
        statusl.pop()
    return


# In[15]:


# 深度搜索寻找路径
def dfs(s,good,bad):
    s = tuple(s)     #字典的值是列表里面包含元组，原因是字典的键值不能是列表
    if s in route:   #已经在路徑里面
        route.append(s)
        return
    # 到達終點，紀錄路径
    if s == (0, 0, good, bad, -1):
        route.append(s)
        way.append(route[:])
        return

    route.append(s)
    for i in range(len(g[s])):
        dfs(g[s][i],good,bad)   #搜索直到到達終點或者重複
        route.pop()


# In[30]:


def main():
    good=int(input("請輸入傳教士人數"))
    bad=int(input("請輸入食人族人數"))
    
    #limitprice=int(input("請輸入限制金額 (若不設限請輸入999999) "))
    #limittime=int(input("請輸入限制次數 (若不設限請輸入999999) "))
    
    starttime=time.time()
    start = [good, bad, 0, 0, 1]
    statusl.append(start)
    result(start)
    dfs(start,good,bad)
    before=[good,bad,0,0,1]
    after=[good,bad,0,0,1]
    num = 0   # 统计次数
    times =0
    price=0
    mintime=99999
    minprice=999999
    maxtime=0
    maxprice=0
    limitmaxprice=0
    limitminprice=999999
    limitmaxtime=0
    limitmintime=999999
    rateA=3
    rateB=25
    numrateA=0
    numrateB=0
    hour=0
    maxhour=0
    minhour=999999
    node=0
    # 输出路径
    for k in way:
        num += 1
        #print("第%d條路徑：" % num)
        #print("左傳教士,左食人族,右傳教士,右食人族,  船 ")
        for i in k:
            #print("{}       {}        {}        {}        {}   ".format(i[0], i[1], i[2], i[3], i[4]))
            if i==way[0][0]:
                continue
            times += 1

            for j in range(5):
                after[j]=i[j]
            
            if abs(before[0]-after[0])+abs(before[1]-after[1])==3:#三人船動作後前後狀態差距6
                price=price+25
                #numrateB+=numrateB
            elif abs(before[2]-after[2])+abs(before[3]-after[3])==3:
                price=price+25
                #numrateB=numrateB+1
            else:
                price=price+3
                #numrateA=numrateA+1
            
            for k in range(5):
                before[k]=after[k]
            node+=1
        #print("此次船移動了%d次"%times)
        """
        if price<limitprice:
            if price>limitmaxprice:
                limitmaxprice=price
            if price<limitminprice:
                limitminprice=price
            if times>limitmaxtime:
                limitmaxtime=times
            if times<limitmintime:
                limitmintime=times
        if times<limittime:
            if price>limitmaxprice:
                limitmaxprice=price
            if price<limitminprice:
                limitminprice=price
            if times>limitmaxtime:
                limitmaxtime=times
            if times<limitmintime:
                limitmintime=times
        """
        if price<minprice:
            minprice=price
        if price>maxprice:
            maxprice=price
        if times>maxtime:
            maxtime=times
        if times<mintime:
            mintime=times
        hour=numrateA*rateA+numrateB*rateB
        #print("此次共花費%d的金錢"%price)
        #print("此次耗費的時間%d小時"%hour)
        if hour>maxhour:
            maxhour=hour
        if hour<minhour:
            minhour=hour
        times=0
        price=0
        before=[good,bad,0,0,1]
        after=[good,bad,0,0,1]
        numrateA=0
        numrateB=0
    
    print("總共有%d條路徑" % num)
    print("最低花費%d元" %minprice)
    print("船隻最少操作%d次"%mintime)
    print("節點有%d個"%node)
    #print("最高花費%d元"%maxprice)
    #print("船隻最多操作%d次"%maxtime)
    #print("最多耗時%d小時"%maxhour)
    #print("最少耗時%d小時"%minhour)
    """
    print("被限制後的最少次數",limitmintime)
    print("被限制後的最多次數",limitmaxtime)
    print("被限制後的最少金錢",limitminprice)
    print("被限制後的最多金錢",limitmaxprice)
    """
    endtime=time.time()
    totaltime=endtime-starttime
    print("此次花費",totaltime,"時間")

    os.system("pause")


# In[31]:


if __name__ == '__main__':
    num = 0   # 统计次数
    times =0
    price=0
    mintime=99999
    minprice=999999
    maxtime=0
    maxprice=0
    main()


# In[ ]:




