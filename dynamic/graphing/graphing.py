import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
standard_file = pd.read_csv('../data/data.csv')


x_axis = standard_file['Size']
y_axis = standard_file[' Recursion Time']
x_axis_2 = standard_file['Size']
y_axis_2 = standard_file[' DP time']


plt.plot(x_axis, np.log2(y_axis), label= "recursion")
plt.plot(x_axis_2, np.log2(y_axis_2), label="dynamic programming")
plt.xlabel("size")
plt.ylabel("Log 2 (Time in s)")
plt.legend()
plt.show()