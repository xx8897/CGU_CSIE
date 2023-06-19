#!/usr/bin/env python
# coding: utf-8

# In[1]:


import operator
import time
import os


# In[2]:


#判斷是否成功
def isgoal(node):
    if node[0]==0 and node[1]==0 and node[2]==0:
        return True
    else:
        return False


# In[3]:


good=int(input("請輸入傳教士人數"))
bad=int(input("請輸入食人族人數"))


# In[4]:


#判斷狀態是否能夠成立
def islegal(node):
    if 0<=node[0]<=good and 0<=node[1]<=bad:
        if node[0]==0:
            return True
        if node[0]>=node[1]:
            return True
        else:
            return False
    else:
        return False


# In[5]:


#判斷是否在closed表中
def isclosed(node):
    global closed
    flag=0
    for n in closed:
        if operator.eq(n,node):
            flag=1
            break
    if flag==1:
        return True
    else:
        return False


# In[6]:


#判斷是否在opened表中
def isopen(node):
    global opened
    flag=0
    for n in opened:
        if operator.eq(n,node):
            flag=1
            break
    if flag==1:
        return True
    else:
        return False


# In[7]:


#將節點擴展，求子節點
#按照五條可能的操作規則：(1,0),(0,1),(1,1),(2,0),(0,2)
#返回一個包含有五個元素的元组，元组可以作為函数返回值
def Expand(node):
    b=node[2]
    node1=()
    node2=()
    node3=()
    node4=()
    node5=()
    tnode=()
    if b==1:
        node1=(node[0]-1,node[1],0)#注意node是元组，不允許修改
        node2=(node[0],node[1]-1,0)
        node3=(node[0]-1,node[1]-1,0)
        node4=(node[0]-2,node[1],0)
        node5=(node[0],node[1]-2,0)
    else:
        node1=(node[0]+1,node[1],1)
        node2=(node[0],node[1]+1,1)
        node3=(node[0]+1,node[1]+1,1)
        node4=(node[0]+2,node[1],1)
        node5=(node[0],node[1]+2,1)
    tnode=(node1,node2,node3,node4,node5)
    return tnode


# In[8]:


#合法的且不在closed表中的子節點添加到opened表中
#使用的insert方法在opened表的頭存入節點
#使得opened列表=stack的功能深度優先搜索
def Toopen(tnode):
    global opened
    for m in tnode:
        if islegal(m) and isclosed(m)==False:
            opened.insert(0,m)
            print("open新增了",m)


# In[9]:


#將合法的，且不在closed表中的子结点和得到的對應的操作添加到result字典中
#注意必须要求不在closed表中，否则字典會將之前的值覆蓋
#也會將其和對應操作儲存，覆蓋掉之前有效節點
def Toresult(ltnode):
    global result
    if isclosed(ltnode[0])==False and islegal(ltnode[0]):
        result[ltnode[0]]=(1,0)
        print("closed新增了",(1,0))
    if isclosed(ltnode[1])==False and islegal(ltnode[1]):
        result[ltnode[1]]=(0,1)
        print("closed新增了",(0,1))
    if isclosed(ltnode[2])==False and islegal(ltnode[2]):
        result[ltnode[2]]=(1,1)
        print("closed新增了",(1,1))
    if isclosed(ltnode[3])==False and islegal(ltnode[3]):
        result[ltnode[3]]=(2,0)
        print("closed新增了",(2,0))
    if isclosed(ltnode[4])==False and islegal(ltnode[4]):
        result[ltnode[4]]=(0,2)
        print("closed新增了",(0,2))


# In[10]:


#判斷closed表中的節點的子節點是否在opened表中或在closed表中
#即該節點已被訪問，不是目標狀態，且不存在子節點或子節點下不存在有效路徑
#將從closed表中删除
#因為最後closed表中存放的是一條有效路徑，所以需要將無效節點删除
def cino():
    global closed
    for k in closed:
        flag1=0
        for x in Expand(k):
            if isopen(x) or isclosed(x):
                flag1=1
        if flag1==0 :
            closed.remove(k)
            print("closed移除了",k)


# In[11]:


node=(good,bad,1)#初始節點
opened=[]
closed=[]
result={}#使用dictionary，可以利用键值来存放節點狀態和操作
opened.insert(0,node)


# In[12]:


start=time.time()
while opened:
    nodet=opened.pop(0)
    #pop操作直接删除指定位置的元素並返回值，取出最開始的元素
    #後進先出，深度優先
    if isgoal(nodet):
        closed.append(nodet)
        print("操作前(人，野，船)：    操作：   操作後：")
        for i in range(0,len(closed)):
            if (i+1)<len(closed):
                print("步驟",i+1,closed[i]," ",result[closed[i+1]],"     ",closed[i+1])
                #已经搜索到目标節點，输出closed表中的有效路徑
                #並從result字典中寻找狀態對應的操作並输出
        break
    if isclosed(nodet)==False:
        closed.append(nodet)#若不在closed表中，將其加入
        snode=Expand(nodet)#求目前節點的子節點，用元组返回
        Toopen(snode)#將有效子節點添加到opened表中
        Toresult(snode)#將有效節點和對應操作存入result字典中
        cino()#將closed表中的無效節點删除
end=time.time()
time=float(end-start)
print("計算時間:總共",time)
os.system("pause")


# In[ ]:





# In[ ]:




