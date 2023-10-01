import matplotlib.pyplot as plt
import pandas as pd
standard_file = pd.read_csv('../data/standard.csv')
print(standard_file[' Sample Size'])
x_axis = standard_file['Number of Digits']
y_axis = standard_file[' Time']
x_axis = x_axis[3::5]
y_axis = y_axis[3::5]
radix_file = pd.read_csv('../data/decimal.csv')
x_axis2 = radix_file['Number of Digits']
y_axis2 = radix_file[' Time']
plt.plot(x_axis, y_axis)
plt.xlabel("X-Axis")
plt.ylabel("Y-Axis")
plt.show()