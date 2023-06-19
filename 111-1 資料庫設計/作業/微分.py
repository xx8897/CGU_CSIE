from sympy import symbols, cos, diff
import numpy as np
coef=[]
print("這裡是個能夠處理微分的計算機")
fpow=int(input("輸入你想要的最高次方："))
item=fpow
for i in range(0,item+1):
    print("請輸入",item-i,"次方係數= ",end="")
    x=float(input()) 
    coef.append(x)
print("f()=",end="")
print(str(coef[0])+"x^"+str(fpow),end=" ")
for i in range(1,item+1):
    if(np.sign(coef[i])!=0):
        if(np.sign(coef[i])!=-1):
            print("+",end="")
    print(str(coef[i])+"x^"+str(fpow-i),end=" ")
print("")
dfpow=fpow-1
dcoef=[]
for i in range(0,item+1):
    dcoef.append(coef[i]*(fpow-i))
print("f'()=",end="")
print(str(dcoef[0])+"x^"+str(dfpow),end=" ")
for i in range(1,item+1):
    if(np.sign(dcoef[i])!=0):
        if(np.sign(dcoef[i])!=-1):
            print("+",end="")
        print(str(dcoef[i])+"x^"+str(dfpow-i),end=" ")
print("")
