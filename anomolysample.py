import numpy as np
import matplotlib.pyplot as plt

# Generate example data (replace this with your own data)
np.random.seed(0)
data = np.random.normal(loc=10, scale=1, size=50)  # Replace with your data

# Constants
sample_size = 5  # Size of each sample
num_samples = len(data) // sample_size

# Calculate X-bar (mean) for each sample
sample_means = [np.mean(data[i * sample_size: (i + 1) * sample_size]) for i in range(num_samples)]

# Calculate control limits
mean = np.mean(sample_means)
std_dev = np.std(sample_means)
UCL = mean + 3 * std_dev  # Upper Control Limit
LCL = mean - 3 * std_dev  # Lower Control Limit

# Create time (sample number) axis
time_axis = list(range(1, num_samples + 1))

# Create a plot for the X-bar chart
plt.figure(figsize=(10, 5))
plt.plot(time_axis, sample_means, marker='o', linestyle='-')
plt.axhline(mean, color='r', linestyle='--', label='Mean')
plt.axhline(UCL, color='g', linestyle='--', label='UCL')
plt.axhline(LCL, color='g', linestyle='--', label='LCL')
plt.xlabel('Sample Number')
plt.ylabel('X-bar (Mean)')
plt.title('X-bar Control Chart')
plt.legend()
plt.grid(True)

# Display the chart
plt.show()
