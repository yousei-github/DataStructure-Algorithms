# 8_toolbar_chart.py
"""Toolbar chart."""

# Bokeh
from bokeh.plotting import *
from bokeh.models import *  # Import the relevant tools


"""
1. Customizing the toolbar

Apply theme to current document.
Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
"""
curdoc().theme = "caliber"

# Prepare data:
X_DATA = [1, 2, 3, 4, 5]
Y_DATA = [4, 5, 5, 7, 2]

"""
(1) Positioning the toolbar
To define the position of the toolbar, use the toolbar_location attribute with one of these values: above, below, left, right

(2) Customizing available tools
You can customize which tools Bokeh displays in the toolbar by passing the tools attribute to the figure function.

2. Adding tooltips
Tooltips are little windows that appear when you hover your mouse over a data point or when you tap on a data point.

Tooltips are based on the HoverTool. The hover tool is part of Bokeh's toolbar.
There are several ways to enable tooltips in Bokeh. This is the quickest:
- Import the HoverTool class from bokeh.models.tools.
- Include HoverTool() in the list passed to the tools argument when calling the figure() function.
- Include the tooltips argument when calling the figure() function.

The tooltips argument accepts a string with a special syntax.
Use the "@" symbol to include the name of the source for the data you want Bokeh to display.
This example includes @x and @y. When the browser displays a tooltip, Bokeh replaces both those fields with the actual data from the lists x and y.

Create a new plot with a title, size (Responsive plot sizing), axis labels, axis type, and tool setting
"""
TOOLS_IN_CHART = [PanTool(), BoxZoomTool(), WheelZoomTool(), WheelPanTool(dimension="width"), WheelPanTool(dimension="height"), ZoomInTool(), ZoomOutTool(), ResetTool(), UndoTool(), RedoTool(), SaveTool(), HelpTool(), CrosshairTool(), HoverTool()]
TOOLTIPS = [
    ("index", "$index"),
    ("Data point (x,y)", "Data point ($x, $y)"),
]
plot = figure(title="Toolbar example", sizing_mode="stretch_width",  x_axis_label='x', y_axis_label='y', toolbar_location="left", tools=TOOLS_IN_CHART, tooltips=TOOLTIPS)

# Add some renderers with legend and line thickness to the plot
plot.scatter(X_DATA, Y_DATA, size=10)
plot.line(X_DATA, Y_DATA, color="navy", line_width=2)

"""
1. Customizing the toolbar
(3) Deactivating and hiding the toolbar
- To deactivate the toolbar completely, set toolbar_location to None.
- To make your toolbar hide automatically, set autohide to True.
  With autohide set to True, Bokeh will hide the toolbar unless the mouse is inside the plot area or you tap inside the plot area.
"""
# plot.toolbar_location = None
plot.toolbar.autohide = True

# Similarly, use the logo property of the Toolbar to deactivate the Bokeh logo:
plot.toolbar.logo = None

# Show the results
show(plot)
