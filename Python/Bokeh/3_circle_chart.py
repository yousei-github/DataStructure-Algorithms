# 3_circle_chart.py
"""Circle chart."""

# Bokeh
from bokeh.plotting import *

"""
1. Creating a circle chart

Apply theme to current document.
Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
"""
curdoc().theme = "light_minimal"

# Prepare data:
X_DATA = [1, 2, 3, 4, 5]
Y_CIRCLE_1_DATA = [4, 5, 5, 7, 2]
Y_CIRCLE_2_DATA = [6, 2, 2, 4, 7]

# Create a new plot with a title, size (Responsive plot sizing), and axis labels
plot = figure(title="Circle example", sizing_mode="stretch_width", x_axis_label='x', y_axis_label='y')

# Add circle renderers with legend and line thickness to the plot
plot.scatter(X_DATA, Y_CIRCLE_1_DATA, legend_label="Circle 1", color="#bb5566", size=16)  # Color is an alias that automatically sets all color properties of an object to the same color

"""
In Bokeh, you can specify colors in several ways. For example:
- Use one of the named CSS colors (for example, "firebrick", https://www.w3.org/TR/css-color-4/#named-colors)
- Use hexadecimal values, prefaced with a # (for example "#00ff00")
- Use a 3-tuple for RGB colors (for example, (100, 100, 255)
- Use a 4-tuple for RGBA colors (for example (100, 100, 255, 0.5))
"""

scatter = plot.scatter(
    X_DATA,
    Y_CIRCLE_2_DATA,
    marker="circle",
    size=80,  # The size of the circles (in screen units or data units)
    legend_label="Circle 2",  # legend entry for the circles
    fill_color="blue",  # The fill color of the circles
    fill_alpha=0.5,  # The transparency of the fill color (any value between 0 and 1)
    line_color="blue",  # The fill color of the circles' outlines
)

"""
2. Altering properties of existing glyphs
If you want to change any property after creating an object, you can define and overwrite the object's attributes directly.
To change the color of your circles from red to blue, you first need to assign a variable name (such as scatter)
Next, use that variable to access the object's glyph attribute and change its properties:
"""
glyph = scatter.glyph
glyph.fill_color = "red"


"""
3. Setting background colors
To change the appearance of the plane that Bokeh draws your plot elements on, use the various fill_color attributes of your Plot object:
"""
plot.background_fill_color = (120, 220, 220)
plot.border_fill_color = "#9be6a9"
plot.outline_line_color = (255, 0, 0)

# Show the results
show(plot)
