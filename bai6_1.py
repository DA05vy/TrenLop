import numpy as np
import matplotlib.pyplot as plt

x = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
y = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])

x_func = np.linspace(-10, 10, 400)
y_func = 3 * x_func ** 3 - 3 * x_func ** 2 + 3 * x_func - 3

plt.figure(figsize=(20, 10))

plt.scatter(x, y, color='red', label='10 diem', s=10)
plt.subplot(1,2,2)
plt.plot(x_func, y_func, color='blue', label='y=3x^3-3x^2+3x-3')


plt.title('Bieu do do thi')
plt.xlabel('x')
plt.ylabel('y')

plt.grid(True)
plt.legend()
plt.show()