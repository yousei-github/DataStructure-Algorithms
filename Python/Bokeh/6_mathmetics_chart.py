# 6_mathmetics_chart.py
"""Mathmetics chart."""

# Bokeh
from bokeh.plotting import *

"""
1. Creating a mathmetics chart

Apply theme to current document.
Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
"""
curdoc().theme = "caliber"

# Prepare data:
X_DATA = [0.1, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0]
Y_LINE_1_DATA = [i**2 for i in X_DATA]
Y_LINE_2_DATA = [10**i for i in X_DATA]
Y_LINE_3_DATA = [10**(i**2) for i in X_DATA]

# Create a new plot with a title, size (Responsive plot sizing), axis labels, axis type, and axis range
plot = figure(title="Mathmetics example", sizing_mode="stretch_width",  x_axis_label='x', y_axis_label='y', y_axis_type="log", y_range=(0.001, 10 ** 11))

# Add some renderers with legend and line thickness to the plot
plot.line(X_DATA, X_DATA, legend_label="y=x")
plot.scatter(X_DATA, X_DATA, legend_label="y=x", fill_color="white", size=8)

plot.line(X_DATA, Y_LINE_1_DATA, legend_label="y=x^2", line_width=3)

plot.line(X_DATA, Y_LINE_2_DATA, legend_label="y=10^x", line_color="red")
plot.scatter(X_DATA, Y_LINE_2_DATA, legend_label="y=10^x", fill_color="red", line_color="red", size=6)

plot.line(X_DATA, Y_LINE_3_DATA, legend_label="y=10^x^2", line_color="orange", line_dash="4 4")

"""
2. Customizing the grid
To change the appearance of the grid, set the various properties of the xgrid(), ygrid(), and grid() methods of your Plot object.
"""

# Change setting on the x-grid
plot.xgrid.grid_line_color = "red"

# Define vertical bonds (Limit the range of x-grid)
plot.xgrid.bounds = (2, 4)

# Change setting only on the y-grid
plot.ygrid.grid_line_alpha = 0.9
plot.ygrid.grid_line_dash = [6, 4]

# Add bands to the y-grid
plot.ygrid.band_fill_color = "olive"
plot.ygrid.band_fill_alpha = 0.1

# Show the results
show(plot)
