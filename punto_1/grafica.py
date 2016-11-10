import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mim

datos=np.genfromtxt("placas.dat")
n=250
Vol=np.zeros((n,n))
Ex=np.zeros((n,n))
Ey=np.zeros((n,n))
i=0
for i in range(n):
    j=0
    for j in range(n):
        Vol[i,j]=datos[j+i*n,2]
        Ex[i,j]=datos[j+i*n,0]
        Ey[i,j]=datos[j+i*n,1]
plt.figure()
plt.imshow(Vol)
plt.savefig("vol.pdf")
plt.close()

X=np.linspace(0,5,250)
Y=np.linspace(0,5,250)

plt.figure()
plt.streamplot(X,Y,Ex,Ey)
plt.savefig("stream.pdf")
plt.close()
    
