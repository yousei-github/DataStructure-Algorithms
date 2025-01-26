# 2_multi_line_chart.py
"""Multi-line chart."""

# Bokeh
from bokeh.plotting import *

# Creating multi-line chart

# Prepare data:
x = [1, 2, 3, 4, 5]
y1 = [6, 7, 2, 4, 5]
y2 = [2, 3, 4, 5, 6]
y3 = [4, 5, 5, 7, 2]

# Create a new plot with a title and axis labels
plot = figure(title="Multiple line example", x_axis_label='x', y_axis_label='y')

# Add multiple renderers with legend and line thickness to the plot
plot.line(x, y1, legend_label="Line 1.", color="blue", line_width=2)
plot.line(x, y2, legend_label="Line 2.", color="red", line_width=2)
plot.line(x, y3, legend_label="Line 3.", color="green", line_width=2)

# Adding and styling a legend
# Use the properties of the Legend object to customize the legend. For example:
# (1) Display legend in top left corner (default is top right corner)
plot.legend.location = "top_left"

# (2) Add a title to your legend
plot.legend.title = "Line Legend"

# (3) Change appearance of legend text
plot.legend.label_text_font = "times"
plot.legend.label_text_font_style = "italic"
plot.legend.label_text_color = "navy"

# (4) Change border and background of legend
plot.legend.border_line_width = 3
plot.legend.border_line_color = "navy"
plot.legend.border_line_alpha = 0.8
plot.legend.background_fill_color = "navy"
plot.legend.background_fill_alpha = 0.2

# Show the results
show(plot)
