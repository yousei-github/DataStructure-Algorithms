# 5_horizontal_bar_chart.py
"""Horizontal bar chart."""

import platform

# Bokeh
from bokeh.plotting import *
from bokeh.palettes import *
from bokeh.models import NumeralTickFormatter
from bokeh.transform import linear_cmap

# Check python version requirement of Bokeh
PYTHON_VERSION = list(map(int, platform.python_version_tuple()))
PYTHON_REQUIREMENT = [3, 10, 0]
if PYTHON_VERSION < PYTHON_REQUIREMENT:
    raise Exception("Must be using Python above " + str(PYTHON_REQUIREMENT) + ", current is " + str(PYTHON_VERSION))

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
SOURCE = ColumnDataSource(dict(y=Y_DATA, left=X_LEFT_DATA, right=X_RIGHT_DATA))

# Create a new plot with a title, size (Responsive plot sizing), axis labels, and axis range
plot = figure(title="Horizaontal bar example", sizing_mode="stretch_width",  x_axis_label='x', y_axis_label='y', y_range=(0, max(Y_DATA) + 5))

"""
2. Color mapping with palettess
Bokeh comes with dozens of pre-defined color palettes that you can use to map colors to your data.
This includes palettes from Brewer, D3, or Matplotlib. See palettes for a list of all available palettes.

First, use the linear_cmap() function to create a color map for your data. The required attributes for this function are:
- field: the data sequence to map colors to
- palette: the palette to use
- low: the lowest value to map a color to
- high: the highest value to map a color to
"""
MAPPER = linear_cmap(field_name="y", palette=Turbo256, low=min(Y_DATA), high=max(Y_DATA))


# Add a circle renderer with legend and line thickness to the plot
plot.hbar(y="y", left="left", right="right", height=0.5, color=MAPPER, source=SOURCE)

"""
3. Setting your axes' appearance
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
