# 5_horizontal_bar_chart.py
"""Horizontal bar chart."""

# Bokeh
from bokeh.plotting import *
from bokeh.models import NumeralTickFormatter

"""
1. Creating a horizontal bar chart

Apply theme to current document.
Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
"""
curdoc().theme = "caliber"

# Prepare data:
X_LEFT_DATA = [1, 2, 3, 4, 5]
X_RIGHT_DATA = [2, 4, 9, 10, 20]
Y_DATA = [1, 2, 3, 4, 5]
source = ColumnDataSource(dict(y=Y_DATA, left=X_LEFT_DATA, right=X_RIGHT_DATA))

# Create a new plot with a title, size (Responsive plot sizing), axis labels, and axis range
plot = figure(title="Horizaontal bar example", sizing_mode="stretch_width",  x_axis_label='x', y_axis_label='y', y_range=(0, 25))

# Add a circle renderer with legend and line thickness to the plot
plot.hbar(y="y", left="left", right="right", height=0.5, fill_color="#b3de69", source=source)

"""
2. Setting your axes' appearance
Options for customizing the appearance of your plot include:
- Setting labels for your axes
- Styling the numbers displayed with your axes
- Defining colors and other layout properties for the axes themselves
"""

# Change some things about the x-axis
plot.xaxis.axis_label = "Time"
plot.xaxis.axis_line_width = 3
plot.xaxis.axis_line_color = "red"

# Change some things about the y-axis
plot.yaxis.axis_label = "Command Issue"
plot.yaxis.major_label_text_color = "orange"
plot.yaxis.major_label_orientation = "vertical"

# Change things on all axes
plot.axis.minor_tick_in = -3
plot.axis.minor_tick_out = 6

# Formatting axis ticks
plot.yaxis.formatter = NumeralTickFormatter(format="0o")

# Show the results
show(plot)
