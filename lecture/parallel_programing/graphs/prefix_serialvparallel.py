import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
serial_file = pd.read_csv('../data/prefix_serial.csv')

x_axis = serial_file['Size']
y_axis = serial_file['Time']
parallel_file = pd.read_csv('../data/prefix_2thread.csv')
x_axis_2thread = parallel_file['Size']
y_axis_2thread = parallel_file['Time']
parallel_file = pd.read_csv('../data/prefix_4thread.csv')
x_axis_4thread = parallel_file['Size']
y_axis_4thread = parallel_file['Time']

plt.plot(x_axis, np.log2(y_axis), label= "serial")
plt.plot(x_axis_2thread, np.log2(y_axis_2thread), label="2 thread")
plt.plot(x_axis_4thread, np.log2(y_axis_4thread), label="4 thread")
plt.xlabel("size")
plt.ylabel("Log 2 (Time in s)")
plt.legend()
plt.show()