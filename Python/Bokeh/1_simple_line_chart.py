# 1_simple_line_chart.py
"""Simple line chart."""

# Bokeh
from bokeh.plotting import *

# The basic idea of Bokeh is a two-step process:
# First, you select from Bokeh’s building blocks to create your visualization.
# Second, you customize these building blocks to fit your needs.

# To do that, Bokeh combines two elements:
# (1) A Python library for defining the content and interactive functionalities of your visualization.
# (2) A JavaScript library called BokehJS that is working in the background to display your interactive visualizations in a web browser.

# Creating a simple line chart
# When you execute these lines of code, Bokeh creates an output file "1_simple_line_chart.html"

# Define two lists containing the data for your line chart:
x = [1, 2, 3, 4, 5]
y = [6, 7, 2, 4, 5]

# Create a new plot with a title and axis labels
plot = figure(title="Simple line example", x_axis_label='x', y_axis_label='y')

# Add a line renderer with legend and line thickness to the plot
plot.line(x, y, legend_label="Temp.", line_width=2)

# Show the results
show(plot)
