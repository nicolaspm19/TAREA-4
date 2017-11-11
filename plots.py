import matplotlib.pyplot as plt
import numpy as np

cond_ini = np.genfromtxt("cond_ini_cuerda.dat")
x = cond_ini[:,0]
y = cond_ini[:,1] 

resultados = np.genfromtxt("resultados.dat") #Lectura y almacenamieto de datos del archivo Ondas.c
fila1 = resultados[0:]
fila2 = resultados[1:]
fila3 = resultados[2:]
fila4 = resultados[3:]

plt.figure()
plt.plot(fila1)
plt.plot(fila2)
plt.plot(fila3)
plt.plot(fila4)
plt.show()
#print fila2

