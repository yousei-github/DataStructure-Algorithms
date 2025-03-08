# 4_vertical_bar_chart.py
"""Vertical bar chart."""

import platform

# Bokeh
from bokeh.models import BoxAnnotation
from bokeh.plotting import *

# Check python version requirement of Bokeh
PYTHON_VERSION = list(map(int, platform.python_version_tuple()))
if PYTHON_VERSION < [3, 10, 0]:
    print("Error: Running Python below 3.10.0, current is " + str(PYTHON_VERSION))
    exit(1)

"""
1. Creating a vertical bar chart

Apply theme to current document.
Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
"""
curdoc().theme = "caliber"

# Prepare data:
X_DATA = [1, 2, 3, 4, 5]
Y_BAR_DATA = [10, 30, 50, 75, 90]

# Create a new plot with a title, size (Responsive plot sizing), and axis labels
plot = figure(title="Vertical bar example", sizing_mode="stretch_width",  x_axis_label='x', y_axis_label='y')

# Add a vertical bar renderer with legend and line thickness to the plot
plot.vbar(x=X_DATA, top=Y_BAR_DATA, legend_label="Vertical bar 1", width=0.5, bottom=0, color="red")

"""
2. Using annotations
Annotations are visual elements that you add to your plot to make it easier to read.
One example are box annotations. You can use box annotations to highlight certain areas of your plot:
(1) To add box annotations to your plot, you first need to import the BoxAnnotation class from bokeh.models:
"""

# (2) Next, create the BoxAnnotation objects. If you do not pass a value for bottom or top, Bokeh automatically extends the box's dimension to the edges of the plot:
low_box = BoxAnnotation(top=20, fill_alpha=0.2, fill_color="#F0E442")
mid_box = BoxAnnotation(bottom=20, top=80, fill_alpha=0.2, fill_color="#009E73")
high_box = BoxAnnotation(bottom=80, fill_alpha=0.2, fill_color="#F0E442")

# (3) Finally, you need to add the BoxAnnotation objects to your existing figure. Use the add_layout() method to add your boxes:
plot.add_layout(low_box)
plot.add_layout(mid_box)
plot.add_layout(high_box)

# Show the results
show(plot)
