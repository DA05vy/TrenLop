import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-10,10, 400)
y = np.sin(x)

x_start = np.linspace(-10,10,100)
y_start = np.sin(x_start)


plt.figure(figsize=(10,6))

plt.plot(x,y,color='b', label='y=sin(x)')

plt.scatter(x_start, y_start, color='r', marker='*', s=100, label='Noi bat')

plt.title('Do thi y = sin(x)', fontsize=14, pad=15)
plt.xlabel('Truc X', fontsize=12)
plt.grid(True)
plt.show()
