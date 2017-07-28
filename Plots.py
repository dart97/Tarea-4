import numpy as np 
import matplotlib.pyplot as plt 


infile = np.genfromtxt('map_data.txt')
infile2 = np.genfromtxt('mapamundi.txt')

x = infile2[:,0]
y = infile2[:,1]
r = infile2[:,2]
theta=np.linspace(0,2*np.pi,100)
punto = r.argmax()
rk=r[punto].mean()
X=rk*np.cos(theta)+ x[punto]
Y=rk*np.sin(theta)+ y[punto]
plt.plot(y,x)
plt.plot([y[punto]],[x[punto]])

plt.imshow(infile)
plt.scatter(x[punto],y[punto])
plt.xlabel('$X$')
plt.ylabel('$Y$')
plt.title('Punto Nemo')
plt.savefig('PuntoNemo.pdf')
plt.close()