import numpy as np
import matplotlib.pyplot as plt

x_bar = np.array([1, 2, 3, 4, 5, 6, 7, 8])
y_bar = np.array([100,90,300,50,50,140,200,80])

y_hist_data = y_bar
y_pie_data = y_bar

# --- Create Subplots ---
# 1 row, 3 columns for the three plots
fig, axes = plt.subplots(1, 3, figsize=(18, 5)) # Adjusted figsize for better layout

# --- Plot 1: Bar Chart ---
ax1 = axes[0]
ax1.bar(x_bar, y_bar, color='red')
ax1.set_title('BAR CHART', fontsize=10, fontweight='bold')
ax1.set_xlabel('x axis', fontsize=8)
ax1.set_ylabel('y axis', fontsize=8)
ax1.tick_params(axis='both', which='major', labelsize=8)
ax1.grid(True, linestyle='--', alpha=0.7, linewidth=0.5)
# Set y-axis limits similar to the image
ax1.set_ylim(0, 320)
ax1.set_yticks(np.arange(0, 301, 50))


# --- Plot 2: Histogram ---
ax2 = axes[1]
# Define bins to somewhat match the image (0-50, 50-100, etc.)
bins_hist = [0, 50, 100, 150, 200, 250, 300]
ax2.hist(y_hist_data, bins=bins_hist, color='green', edgecolor='black', rwidth=0.95) # rwidth to make bars not touch perfectly
ax2.set_title('HISTOGRAM CHART', fontsize=10, fontweight='bold')
ax2.set_xlabel('x axis', fontsize=8) # In a histogram, this x-axis represents the values of 'y'
ax2.set_ylabel('y axis', fontsize=8) # In a histogram, this y-axis represents frequency
ax2.tick_params(axis='both', which='major', labelsize=8)
ax2.grid(True, linestyle='--', alpha=0.7, linewidth=0.5)
# Set y-axis limits similar to the image
ax2.set_ylim(0, 5)
ax2.set_yticks(np.arange(0, 6, 1))
# Set x-axis ticks to match bin edges for clarity
ax2.set_xticks(bins_hist)


# --- Plot 3: Pie Chart ---
ax3 = axes[2]
# Create more distinct colors if default cycle isn't enough or desired
# Using a colormap to get varied colors like the example
colors = plt.cm.get_cmap('tab20', len(y_pie_data)) # 'tab20' has 20 distinct colors

# Explode a slice if desired (optional, not explicitly in image but common for emphasis)
# explode = [0] * len(y_pie_data)
# if len(y_pie_data) > 0:
# explode[2] = 0.1 # Explode the 3rd slice (corresponding to the 300 value)

ax3.pie(y_pie_data,
        # labels=[f'Val {v}' for v in y_pie_data], # Optional: add labels to slices
        autopct='%1.1f%%', # Optional: show percentages
        startangle=90,      # Start the first slice at the top
        colors=colors.colors, # Use the generated colors
        # explode=explode # Apply explode if defined
       )
ax3.set_title('PIE CHART', fontsize=10, fontweight='bold')
ax3.axis('equal') # Ensures pie is drawn as a circle.


# --- Final Adjustments and Show Plot ---
plt.tight_layout(pad=2.0) # Adjust padding between subplots and figure edges
plt.suptitle('Bài 6.4. Bar, histogram, pie, subplots', fontsize=14, fontweight='bold', y=1.02) # Overall title
plt.show()
