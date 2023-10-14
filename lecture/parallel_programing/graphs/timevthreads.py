import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

parallel_file = pd.read_csv('../data/parallel_mult.csv')
x_axis_2thread = parallel_file['Num Threads'][np.where(parallel_file['Matrix Size'] == 512)[0]]
y_axis_2thread = parallel_file['Time'][np.where(parallel_file['Matrix Size'] == 512)[0]]



plt.plot(x_axis_2thread, y_axis_2thread, label="time")

plt.xlabel("threads")
plt.ylabel("Time in s")
plt.legend()
plt.show()