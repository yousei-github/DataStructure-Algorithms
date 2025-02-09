# 2_multi_line_chart.py
"""Multi-line chart."""

# Bokeh
from bokeh.plotting import *

"""
1. Creating multi-line chart

Apply theme to current document.
Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
"""
curdoc().theme = "caliber"

# Prepare data:
X_DATA = [1, 2, 3, 4, 5]
Y_LINE_1_DATA = [6, 7, 2, 4, 5]
Y_LINE_2_DATA = [2, 3, 4, 5, 6]
Y_LINE_3_DATA = [4, 5, 5, 7, 2]

# Create a new plot with a title, size (Responsive plot sizing), and axis labels
plot = figure(title="Multiple line example", sizing_mode="stretch_width", height=250, x_axis_label='x', y_axis_label='y')

# Add multiple renderers with legend and line thickness to the plot
plot.line(X_DATA, Y_LINE_1_DATA, legend_label="Line 1.", color="blue", line_width=2)
plot.line(X_DATA, Y_LINE_2_DATA, legend_label="Line 2.", color="red", line_width=2)
plot.line(X_DATA, Y_LINE_3_DATA, legend_label="Line 3.", color="green", line_width=2)

"""
2. Adding and styling a legend
Use the properties of the Legend object to customize the legend. For example:
(1) Display legend in top left corner (default is top right corner)
"""
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
