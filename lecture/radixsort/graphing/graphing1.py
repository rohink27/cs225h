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
x_axis2 = x_axis2[3::5]
y_axis2 = y_axis2[3::5]
y_axis = 1000 * y_axis
y_axis2 = 1000 * y_axis2
plt.plot(x_axis, y_axis, label= "recursion")
plt.plot(x_axis2, y_axis2, label="dp")
plt.xlabel("Number of Digits")
plt.ylabel("Time in ms")
plt.legend()
plt.show()