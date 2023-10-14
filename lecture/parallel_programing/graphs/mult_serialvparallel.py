import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
serial_file = pd.read_csv('../data/Serial_mult.csv')

x_axis = serial_file['Matrix Size']
y_axis = serial_file['Time']
parallel_file = pd.read_csv('../data/parallel_mult.csv')
x_axis_2thread = parallel_file['Matrix Size']
y_axis_2thread = parallel_file['Time']
x_axis_2thread = x_axis_2thread[0::6]
y_axis_2thread = y_axis_2thread[0::6]
x_axis_4thread = parallel_file['Matrix Size']
y_axis_4thread = parallel_file['Time']
x_axis_4thread = x_axis_4thread[1::6]
y_axis_4thread = y_axis_4thread[1::6]

plt.plot(x_axis, np.log2(y_axis), label= "serial")
plt.plot(x_axis_2thread, np.log2(y_axis_2thread), label="2 thread")
plt.plot(x_axis_4thread, np.log2(y_axis_4thread), label="4 thread")
plt.xlabel("Matrix size")
plt.ylabel("Log 2 (Time in s)")
plt.legend()
plt.show()