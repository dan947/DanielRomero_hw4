import numpy as np
import sys
import matplotlib.pylab as plt
import os

datos=np.genfromtxt("cuerda.dat")
cuerda=np.zeros((200,100))
for j in range (200):
    for i in range(100):
        cuerda[j,i]=datos[i+j*100]

s=0
for s in range(200):
    plt.figure()
    plt.plot(np.arange(100),cuerda[s,:])
    name='I_%05d.png' %s
    plt.ylim((-5,5))
    plt.savefig(name)
    plt.close()
    s+=1
os.system('convert -delay 10 -loop 0 *png cuerda.gif')
os.system('rm *.png')
