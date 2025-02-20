import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv('results.csv')

# extract unique gap codes (0, 1, 2, 3) and input sizes (n)
gap_codes = data['code'].unique()
sizes = data['n'].unique()

# initialize a figure for plotting
plt.figure(figsize=(12, 6))

# graph 1: plot n vs average number of swaps for each gap code
plt.subplot(1, 2, 1)  # (rows, cols, subplot index)
for code in gap_codes:
    # filters data for the current gap code
    subset = data[data['code'] == code]
    avg_swaps = subset['avg_comparisons']  # extract average comparisons (swaps)
    
    # plot n vs avg_swaps
    plt.plot(subset['n'], avg_swaps, label=f'Code {code}')

# graph 1 details
plt.title('Graph 1: n vs Average Number of Comparisons')
plt.xlabel('n (Input Size)')
plt.ylabel('Average Number of Comparisons')
plt.legend()

# graph 2: plot log(n) vs log(average number of swaps) for each gap code
plt.subplot(1, 2, 2)
for code in gap_codes:
    # filters data for the current gap code
    subset = data[data['code'] == code]
    avg_swaps = subset['avg_comparisons']

    log_n = np.log2(subset['n']) # log base 2 of n
    log_avg_swaps = np.log2(avg_swaps)
    
    # plot log(n) vs log(avg_swaps)
    plt.plot(log_n, log_avg_swaps, label=f'Code {code}')

# graph 2 details
plt.title('Graph 2: log(n) vs log(Average Number of Comparisons)')
plt.xlabel('log(n)')
plt.ylabel('log(Average Number of Comparisons)')
plt.legend()

# display the plots
plt.tight_layout()  # adjust layout to avoid overlap
plt.show()
