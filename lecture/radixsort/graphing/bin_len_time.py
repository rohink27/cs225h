import matplotlib.pyplot as plt
import pandas as pd
standard_file = pd.read_csv('../data/standard_like.csv')
print(standard_file[' Sample Size'])
x_axis = standard_file['Number of Digits']
y_axis = standard_file[' Time']

radix_file = pd.read_csv('../data/optimised_decimal.csv')
x_axis2 = radix_file['Number of Digits']
y_axis2 = radix_file[' Time']

y_axis = 1000 * y_axis
y_axis2 = 1000 * y_axis2
plt.plot(x_axis, y_axis, label= "standard sort")
plt.plot(x_axis2, y_axis2, label="radix sort")
plt.xlabel("Number of Digits")
plt.ylabel("Time in ms")
plt.legend()
plt.show()