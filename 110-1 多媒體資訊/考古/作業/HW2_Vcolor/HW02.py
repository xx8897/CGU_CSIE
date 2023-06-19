# -*- coding: utf-8 -*-
"""
Created on Mon Dec 23 14:31:30 2019

@author: user
"""
from scipy.ndimage.filters import convolve

# tqdm并非必需，但能为提供很美观的进度条，方便我们查看进度

import numpy as np
import cv2
from PIL import Image
from scipy.misc import imread

def calc_energy(img1):
    filter_du = np.array([
       [1.0, 2.0, 1.0],
		[0.0, 0.0, 0.0],
		[-1.0, -2.0, -1.0],
    ])
    # 这会将它从2D滤波转换为3D滤波器
    # 为每个通道：R，G，B复制相同的滤波器
    filter_du = np.stack([filter_du] * 3, axis=2)

    filter_dv = np.array([
        [1.0, 0.0, -1.0],
		[2.0, 0.0, -2.0],
		[1.0, 0.0, -1.0],
    ])
    # 这会将它从2D滤波转换为3D滤波器
    # 为每个通道：R，G，B复制相同的滤波器
    filter_dv = np.stack([filter_dv] *3, axis=2)

    img1 = img1.astype('float32')
    convolved = np.absolute(convolve(img1, filter_du)) + np.absolute(convolve(img1, filter_dv))

    # 我们将红，绿，蓝通道中的能量相加
    energy_map = convolved.sum(axis=2)
    return energy_map
 


img = cv2.imread('sflower.jpg')
# 根据jpg生成raw
img.tofile('sflower.raw')
 
type = img.dtype
width, height, channels = img.shape
print(type,width, height, channels)
 

imgData = np.fromfile('sflower.raw', dtype=type)
 

imgData = imgData.reshape(width, height, channels)

import matplotlib.pyplot as pyplot#cv2中的色彩排列是(b,g,r)，而matplotlib库中的排列方式是(r,g,b)
imgData_rgb=imgData[:,:,::-1]#修改色彩排列
pyplot.imshow(imgData_rgb)
pyplot.axis("off") 
pyplot.savefig('sflower1.jpg',bbox_inches='tight',dpi=100,pad_inches=0.0)#将当前图像保存为一张jpg图像，放在.show后面会变成空图
pyplot.show()


gray = Image.open('sflower1.jpg').convert('I')
pyplot.axis("off") 
pyplot.imshow(gray, cmap="gray",)
pyplot.savefig('I-Channel.jpg',bbox_inches='tight',dpi=100,pad_inches=0.0)
pyplot.show()


energy1 = cv2.imread('I-Channel.jpg')
energy2 = calc_energy(energy1)

pyplot.axis("off")
pyplot.imshow(energy2)
pyplot.savefig('./Irfanview395/1/sflower3.jpg',bbox_inches='tight',dpi=100,pad_inches=0.0)
pyplot.show()



im = imread("./Irfanview395/1/sflower3.jpg")
gray1 = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
#retval, im_at_fixed = cv2.threshold(gray1, 70, 255, cv2.THRESH_BINARY) 
pyplot.axis("off") 
pyplot.imshow(gray1, cmap = 'gray')
pyplot.savefig('energy_map.jpg',bbox_inches='tight',dpi=100,pad_inches=0.0)
pyplot.show()


im_gray = cv2.imread('energy_map.jpg')
im_color = cv2.applyColorMap(im_gray, cv2.COLORMAP_HSV)
pyplot.axis("off") 
pyplot.imshow(im_color)
pyplot.savefig('Virtua_color.jpg',bbox_inches='tight',dpi=100,pad_inches=0.0)
#pyplot.savefig('sflower4.jpg',bbox_inches='tight',dpi=150,pad_inches=0.0)
pyplot.show()

