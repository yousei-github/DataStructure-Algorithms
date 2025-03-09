# 10_widget_chart.py
"""Widget chart."""

import platform

# Bokeh
import bokeh.layouts
from bokeh.plotting import *
from bokeh.models import *  # Import the relevant tools

# Check python version requirement of Bokeh
PYTHON_VERSION = list(map(int, platform.python_version_tuple()))
if PYTHON_VERSION < [3, 10, 0]:
    print("Error: Running Python below 3.10.0, current is " + str(PYTHON_VERSION))
    exit(1)

"""
1. Creating a widget chart
Widgets are additional visual elements that you can include in your visualization.
Use widgets to display additional information or to interactively control elements of your Bokeh document.

For example, types of widgets are:
- A Div widget to display HTML text
- A Spinner widget to select a numeric value
- A RangeSlider widget to adjust a range

See Bokeh's built-in widgets in the user guide for a complete list of Bokeh's widgets (https://docs.bokeh.org/en/latest/docs/user_guide/interaction/widgets.html#ug-interaction-widgets-examples).

"""
curdoc().theme = "caliber"

FIGURE_HEIGHT = 800
FIGURE_WIDTH = 800

# Prepare data:
X_DATA = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Y_DATA = [4, 5, 5, 7, 2, 6, 4, 9, 1, 3]

SOURCE = ColumnDataSource(data=dict(x_values=X_DATA, y_values=Y_DATA))

FIGURE_X_RANGE_START = 0
FIGURE_X_RANGE_END = int(max(X_DATA)*1.1)

# Create a new plot with a title, size (Responsive plot sizing), axis labels, axis type, and tool setting
TOOLS_IN_CHART = [PanTool(), BoxZoomTool(), WheelZoomTool(), WheelPanTool(dimension="width"), WheelPanTool(dimension="height"), ZoomInTool(), ZoomOutTool(), ResetTool(), UndoTool(), RedoTool(), SaveTool(), HelpTool(), CrosshairTool(), HoverTool()]
TOOLTIPS = [
    ("index", "$index"),
    ("Data point (x,y)", "Data point ($x, $y)"),
]
plot = figure(title="Widget example", x_range=(FIGURE_X_RANGE_START, FIGURE_X_RANGE_END), width=FIGURE_HEIGHT, height=FIGURE_WIDTH,  x_axis_label='x', y_axis_label='y', toolbar_location="left", tools=TOOLS_IN_CHART, tooltips=TOOLTIPS)

# Add some renderers with legend and line thickness to the plot
POINTS = plot.scatter(x="x_values", y="y_values", size=20, source=SOURCE)
plot.line(x="x_values", y="y_values", color="red", line_width=2, source=SOURCE)

# plot.toolbar_location = None
plot.toolbar.autohide = True

# Similarly, use the logo property of the Toolbar to deactivate the Bokeh logo:
plot.toolbar.logo = None

"""
2. Create a Div object and pass it HTML code as a string
"""
DIV = Div(
    text="""
        <p>Select the circle's size using this control element:</p>
        """,
    width=200,
    height=30,
)

"""
3. Create a Spinner object
To link the value generated by the spinner to the size property of your glyph, use the js_link() function.

This function uses JavaScript to interactively link two Bokeh models.
The first argument you pass to this function is the attribute of your spinner ("value") that you want to link to your circle glyphs.
The second attribute is the glyph you want to link to your spinner (POINTS.glyph).
The third argument is the property of your glyph that you want to link to your spinner's value.
"""
SPINNER = Spinner(
    title="Circle size",  # A string to display above the widget
    low=0,  # The lowest possible number to pick
    high=60,  # The highest possible number to pick
    step=5,  # The increments by which the number can be adjusted
    value=POINTS.glyph.size,  # The initial value to display in the widget
    width=200,  # The width of the widget in pixels
)
SPINNER.js_link("value", POINTS.glyph, "size")

"""
4. Create a RangeSlider object
To link the values generated by the RangeSlider to the existing plot, use the js_link() function.
You need to assign two values at once: the beginning of the plot's x-axis and the end of its x-axis.
The RangeSlider returns a tuple of those two values.
Therefore, you need to use the attr_selector of the js_link() function to tell Bokeh which part of the Tuple to assign to either the start or the end of the plot's x-axis.
"""
RANGE_SLIDER = RangeSlider(
    title="Adjust x-axis range",  # A title to display above the slider
    start=FIGURE_X_RANGE_START,  # Set the minimum value for the slider
    end=FIGURE_X_RANGE_END,  # Set the maximum value for the slider
    step=1,  # Increments for the slider
    value=(plot.x_range.start, plot.x_range.end),  # Initial values for slider
)
RANGE_SLIDER.js_link("value", plot.x_range, "start", attr_selector=0)
RANGE_SLIDER.js_link("value", plot.x_range, "end", attr_selector=1)

# Create a layout with all the elements of your dashboard and display it in a browser:
LAYOUT = bokeh.layouts.layout(
    [
        [DIV, SPINNER],
        [RANGE_SLIDER],
        [plot],
    ],
)

# Show the results
show(LAYOUT)
