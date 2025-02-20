import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Read the CSV file
data = pd.read_csv('results.csv')

# Extract unique gap codes (0, 1, 2, 3) and input sizes (n)
gap_codes = data['code'].unique()
sizes = data['n'].unique()

# Initialize a figure for plotting
plt.figure(figsize=(12, 6))

# Graph 1: Plot n vs average number of swaps for each gap code
plt.subplot(1, 2, 1)  # (rows, cols, subplot index)
for code in gap_codes:
    # Filter data for the current gap code
    subset = data[data['code'] == code]
    avg_swaps = subset['avg_comparisons']  # Extract average comparisons (swaps)
    
    # Plot n vs avg_swaps
    plt.plot(subset['n'], avg_swaps, label=f'Code {code}')

# Customize Graph 1
plt.title('Graph 1: n vs Average Number of Swaps')
plt.xlabel('n (Input Size)')
plt.ylabel('Average Number of Swaps')
plt.legend()

# Graph 2: Plot log(n) vs log(average number of swaps) for each gap code
plt.subplot(1, 2, 2)
for code in gap_codes:
    # Filter data for the current gap code
    subset = data[data['code'] == code]
    avg_swaps = subset['avg_comparisons']
    
    # Plot log(n) vs log(avg_swaps)
    plt.plot(np.log(subset['n']), np.log(avg_swaps), label=f'Code {code}')

# Customize Graph 2
plt.title('Graph 2: log(n) vs log(Average Number of Swaps)')
plt.xlabel('log(n)')
plt.ylabel('log(Average Number of Swaps)')
plt.legend()

# Display the plots
plt.tight_layout()  # Adjust layout to avoid overlap
plt.show()
