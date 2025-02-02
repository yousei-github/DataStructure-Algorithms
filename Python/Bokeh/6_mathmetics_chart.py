# 6_mathmetics_chart.py
"""Mathmetics chart."""

# Bokeh
from bokeh.plotting import *

# 1. Creating a mathmetics chart

# Apply theme to current document.
# Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
curdoc().theme = "caliber"

# Prepare data:
x = [0.1, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0]
y0 = [i**2 for i in x]
y1 = [10**i for i in x]
y2 = [10**(i**2) for i in x]

# Create a new plot with a title, size (Responsive plot sizing), axis labels, axis type, and axis range
plot = figure(title="Mathmetics example", sizing_mode="stretch_width",  x_axis_label='x', y_axis_label='y', y_axis_type="log", y_range=(0.001, 10 ** 11))

# Add some renderers with legend and line thickness to the plot
plot.line(x, x, legend_label="y=x")
plot.scatter(x, x, legend_label="y=x", fill_color="white", size=8)

plot.line(x, y0, legend_label="y=x^2", line_width=3)

plot.line(x, y1, legend_label="y=10^x", line_color="red")
plot.scatter(x, y1, legend_label="y=10^x", fill_color="red", line_color="red", size=6)

plot.line(x, y2, legend_label="y=10^x^2", line_color="orange", line_dash="4 4")

# Show the results
show(plot)
