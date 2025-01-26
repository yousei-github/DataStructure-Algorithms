# 3_circle_chart.py
"""Circle chart."""

# Bokeh
from bokeh.plotting import *

# 1. Creating a circle chart

# Apply theme to current document.
# Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
curdoc().theme = "light_minimal"

# Prepare data:
x = [1, 2, 3, 4, 5]
y = [4, 5, 5, 7, 2]
y2 = [6, 2, 2, 4, 7]

# Create a new plot with a title and axis labels
plot = figure(title="Circle example", x_axis_label='x', y_axis_label='y')

# Add circle renderers with legend and line thickness to the plot
plot.scatter(x, y, legend_label="Circle 1", color="#bb5566", size=16)  # Color is an alias that automatically sets all color properties of an object to the same color

# In Bokeh, you can specify colors in several ways. For example:
# - Use one of the named CSS colors (for example, "firebrick", https://www.w3.org/TR/css-color-4/#named-colors)
# - Use hexadecimal values, prefaced with a # (for example "#00ff00")
# - Use a 3-tuple for RGB colors (for example, (100, 100, 255)
# - Use a 4-tuple for RGBA colors (for example (100, 100, 255, 0.5))

scatter = plot.scatter(
    x,
    y2,
    marker="circle",
    size=80,  # The size of the circles (in screen units or data units)
    legend_label="Circle 2",  # legend entry for the circles
    fill_color="blue",  # The fill color of the circles
    fill_alpha=0.5,  # The transparency of the fill color (any value between 0 and 1)
    line_color="blue",  # The fill color of the circles' outlines
)

# 2. Altering properties of existing glyphs
# If you want to change any property after creating an object, you can define and overwrite the object's attributes directly.
# To change the color of your circles from red to blue, you first need to assign a variable name (such as scatter)
# Next, use that variable to access the object's glyph attribute and change its properties:
glyph = scatter.glyph
glyph.fill_color = "red"

# Show the results
show(plot)
