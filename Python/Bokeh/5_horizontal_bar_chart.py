# 5_horizontal_bar_chart.py
"""Horizontal bar chart."""

# Bokeh
from bokeh.plotting import *

# 1. Creating a horizontal bar chart

# Apply theme to current document.
# Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
curdoc().theme = "caliber"

# Prepare data:
left = [1, 2, 3, 4, 5]
right = [2, 4, 9, 10, 20]
y = [1, 2, 3, 4, 5]
source = ColumnDataSource(dict(y=y, left=left, right=right))

# Create a new plot with a title and axis labels
plot = figure(title="Horizaontal bar example", x_axis_label='x', y_axis_label='y')

# Add a circle renderer with legend and line thickness to the plot
plot.hbar(y="y", left="left", right="right", height=0.5, fill_color="#b3de69", source=source)

# Show the results
show(plot)
