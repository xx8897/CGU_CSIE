import matplotlib.pyplot as plt

labels = ["東部", "南部", "北部", "中部"]
sizes = [5, 10, 20, 15]
colors = ["red", "green", "blue", "yellow"]
explode = (0, 0, 0.05, 0)

plt.pie(sizes,explode = explode,labels = labels,colors = colors,\
    labeldistance = 1.1,autopct = "%3.1f%%",shadow = True,\
    startangle = 90,pctdistance = 0.6)

plt.axis("equal")

plt.legend()

plt.show()



