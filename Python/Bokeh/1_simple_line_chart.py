# 1_simple_line_chart.py
"""Simple line chart."""

import platform

# Bokeh
from bokeh.plotting import *
from bokeh.layouts import row

# Check python version requirement of Bokeh
PYTHON_VERSION = list(map(int, platform.python_version_tuple()))
if PYTHON_VERSION < [3, 10, 0]:
    print("Error: Running Python below 3.10.0, current is " + str(PYTHON_VERSION))
    exit(1)

"""
The basic idea of Bokeh is a two-step process:
First, you select from Bokeh's building blocks to create your visualization.
Second, you customize these building blocks to fit your needs.

To do that, Bokeh combines two elements:
(1) A Python library for defining the content and interactive functionalities of your visualization.
(2) A JavaScript library called BokehJS that is working in the background to display your interactive visualizations in a web browser.
"""

"""
1. Creating a simple line chart
When you execute these lines of code, Bokeh creates an output file "1_simple_line_chart.html"

Apply theme to current document.
Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
"""
curdoc().theme = "caliber"

# Define two lists containing the data for your line chart:
X_DATA = [1, 2, 3, 4, 5]
Y_DATA = [6, 7, 2, 4, 5]

# Create a new plot with a title, size (width & height), and axis labels
plot = figure(title="Simpleline example", width=350, height=250, x_axis_label='x', y_axis_label='y')

# Add a line renderer with legend and line thickness to the plot
# Bokeh automatically adds a legend to your plot if you include the legend_label attribute when calling the renderer function.
plot.line(X_DATA, Y_DATA, legend_label="Line 1.", line_width=2)

"""
2. Customizing headlines
There are various ways to style the text for your headline. For example:
(1) Change headline location to the left
"""
plot.title_location = "left"

# (2) Change headline text
plot.title.text = "Simple line example"

# (3) Style the headline
plot.title.text_font_size = "25px"
plot.title.align = "right"
plot.title.background_fill_color = "darkgrey"
plot.title.text_color = "white"

"""
3. Creating rows, columns, and grids
The easiest way to combine individual plots is to assign them to rows or columns.

To combine several plots into a horizontal row layout, you first need to import row. Then use the row() function when calling show().

To display several plots in a vertical column layout, use the column() function instead.
A more flexible way to arrange elements in Bokeh is to use the gridplot() function.

(1) Defining sizing behavior
You can use the functions row(), column(), and gridplot() with additional arguments to define how Bokeh scales the individual plots.
See sizing_mode for a list of all sizing modes that Bokeh supports.

For example: To make all plots in a row responsively fill the available width of the browser window, assign scale_width to sizing_mode.
"""
plot2 = figure(title="Second figure example", x_axis_label='x', y_axis_label='y')
Y_LINE_2_DATA = [value * (-1) + 10 for value in Y_DATA]
plot2.line(X_DATA, Y_LINE_2_DATA, legend_label="Line 2.", line_width=2)

# Show the results
# show(plot)
show(row(children=[plot, plot2], sizing_mode="scale_width"))
