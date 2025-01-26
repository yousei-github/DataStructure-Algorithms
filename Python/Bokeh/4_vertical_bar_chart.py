# 4_vertical_bar_chart.py
"""Vertical bar chart."""

# Bokeh
from bokeh.models import BoxAnnotation
from bokeh.plotting import *

# 1. Creating a vertical bar chart

# Apply theme to current document.
# Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
curdoc().theme = "caliber"

# Prepare data:
x = [1, 2, 3, 4, 5]
y = [10, 30, 50, 75, 90]

# Create a new plot with a title and axis labels
plot = figure(title="Vertical bar example", x_axis_label='x', y_axis_label='y')

# Add a vertical bar renderer with legend and line thickness to the plot
plot.vbar(x=x, top=y, legend_label="Vertical bar 1", width=0.5, bottom=0, color="red")

# 2. Using annotations
# Annotations are visual elements that you add to your plot to make it easier to read.
# One example are box annotations. You can use box annotations to highlight certain areas of your plot:
# (1) To add box annotations to your plot, you first need to import the BoxAnnotation class from bokeh.models:

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
