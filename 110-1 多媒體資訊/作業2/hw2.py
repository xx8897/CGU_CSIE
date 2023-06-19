import numpy
from PIL import Image
from numpy.core.fromnumeric import transpose

source = 'baboon'

(rows,cols)=(512,512)

def main():
    picture = load(source+'.raw')

    picture = picture.reshape(3,rows, cols)

    R=picture[0]
    G=picture[1]
    B=picture[2]

    peppers_r= Image.fromarray(R)
    peppers_g= Image.fromarray(G)
    peppers_b= Image.fromarray(B)

    peppers_r.save(source+"的r.jpeg") #儲存
    peppers_g.save(source+"的g.jpeg") #儲存
    peppers_b.save(source+"的b.jpeg")  #儲存
    

    yuv = RGB轉換為YUV(picture)
    Y=yuv[0].astype(numpy.uint8)
    U=yuv[1].astype(numpy.uint8)
    V=yuv[2].astype(numpy.uint8)
    
    peppers_y= Image.fromarray(Y)
    peppers_u= Image.fromarray(U)
    peppers_v= Image.fromarray(V)

    peppers_y.save(source+"的y.jpeg")
    peppers_u.save(source+"的u.jpeg")
    peppers_v.save(source+"的v.jpeg")


    yuv_次取樣 = yuv次取樣(yuv,2)
    Y=yuv_次取樣[0].astype(numpy.uint8)
    U=yuv_次取樣[1].astype(numpy.uint8)
    V=yuv_次取樣[2].astype(numpy.uint8)

    peppers_y2= Image.fromarray(Y)
    peppers_u2= Image.fromarray(U)
    peppers_v2= Image.fromarray(V)

    peppers_y2.save(source+"次取樣的y.jpeg") #儲存
    peppers_u2.save(source+"次取樣的u.jpeg") #儲存
    peppers_v2.save(source+"次取樣的v.jpeg") #儲存

    rgb_次取樣 = YUV轉換為RGB(yuv_次取樣)
    yuv_次取樣 = yuv次取樣(yuv,8)
    rgb_次取樣 = YUV轉換為RGB(yuv_次取樣)

    save(source+'_次取樣1.raw',rgb_次取樣) #儲存
    save(source+'_次取樣8.raw',rgb_次取樣) #儲存

def save(filename,picture):  #儲存
    save_array = picture.reshape(3*rows*cols)
    save_array = save_array.astype(numpy.uint8)
    with open(filename, 'wb') as picture:
        save_array.tofile(picture)

def yuv次取樣(yuv,element): 
    yuv_img = yuv.copy()
    for i in range(1,3):              
        for j in range(0,len(yuv_img[0]),element):
            for k in range(0,len(yuv_img[0][0]),element):
                for l in range(element):
                    for m in range(element):
                        yuv_img[i][j+l][k+m] = yuv_img[i][j][k] #次取樣過程
    return yuv_img


def YUV轉換為RGB(picture):
    yuv_picture = picture.copy()
    yuv_reshape = yuv_picture.reshape(3,rows*cols)
    yuv_reshape[1] = [u-128 for u in yuv_reshape[1]]
    yuv_reshape[2] = [v-128 for v in yuv_reshape[2]]
  
    trans = [[1,-0.00093,1.401687],[1,-0.3437,-0.71417],[1,1.77216,0.00099]]
    rgb_trans = trans@yuv_reshape
    rgb = rgb_trans.reshape(3,rows,cols)
    rgb = rgb.astype(numpy.uint8)
    return rgb

def RGB轉換為YUV(picture):
    rgb_reshape = picture.reshape(3,rows*cols)
    offset = [[0],[128],[128]]
    trans = [[0.299,0.587,0.114],[-0.169,-0.331,0.5],[0.5,-0.419,-0.081]]
    
    yuv_reshape = trans@rgb_reshape+offset#重新定義
 
    yuv = yuv_reshape.reshape(3,rows,cols)
    return yuv


def load(filename):  #讀取檔案
    picture = []
    with open(filename, 'rb') as picture:
        picture = numpy.fromfile(picture, dtype=numpy.uint8,count=rows*cols*3)
    return picture

if __name__ == '__main__': #呼叫main
    main()
