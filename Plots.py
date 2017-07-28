import numpy as np 
import matplotlib.pyplot as plt 


infile = np.genfromtxt('map_data.txt')
infile2 = np.genfromtxt('mapamundi.txt')

x = infile2[:,0]
y = infile2[:,1]
r = infile2[:,2]

punto = r.argmax()
print x[punto]
plt.imshow(infile)
plt.scatter(x[punto],y[punto])

plt.show()