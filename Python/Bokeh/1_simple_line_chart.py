# 1_simple_line_chart.py
"""Simple line chart."""

# Bokeh
from bokeh.plotting import *

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
plot = figure(title="simpleline example", width=350, height=250, x_axis_label='x', y_axis_label='y')

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

# Show the results
show(plot)
