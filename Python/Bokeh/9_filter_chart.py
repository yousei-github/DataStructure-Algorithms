# 9_filter_chart.py
"""Filter chart."""

import platform

# Bokeh
from bokeh.plotting import *
from bokeh.models import *  # Import the relevant tools

# Check python version requirement of Bokeh
PYTHON_VERSION = list(map(int, platform.python_version_tuple()))
PYTHON_REQUIREMENT = [3, 10, 0]
if PYTHON_VERSION < PYTHON_REQUIREMENT:
    raise Exception("Must be using Python above " + str(PYTHON_REQUIREMENT) + ", current is " + str(PYTHON_VERSION))

"""
1. Creating a filter chart
So far, you have used data sequences like Python lists and NumPy arrays to pass data to Bokeh.
Bokeh has automatically converted these lists into ColumnDataSource objects for you, which is Bokeh's own data structure.

Follow these steps to create a ColumnDataSource directly:
- First, import ColumnDataSource.
- Next, create a dict with your data: The dict's keys are the column names (strings).
  The dict's values are lists or arrays of data.
- Then, pass your dict as the data argument to ColumnDataSource.
- You can then use your ColumnDataSource as source for your renderer.
"""
curdoc().theme = "caliber"

FIGURE_HEIGHT = 800
FIGURE_WIDTH = 800

# Prepare data:
DATA = {"x_values": [1, 2, 3, 4, 5],
        "y_values": [6, 7, 2, 3, 6]}

# Create ColumnDataSource based on dict
SOURCE_1 = ColumnDataSource(data=DATA)
SOURCE_2 = ColumnDataSource(data=dict(x_values=[1, 2, 3, 4, 5], y_values=[6, 7, 2, 3, 6]))


# Create a new plot with a title, size (Responsive plot sizing), axis labels, axis type, and tool setting
TOOLS_IN_CHART = [PanTool(), BoxZoomTool(), WheelZoomTool(), WheelPanTool(dimension="width"), WheelPanTool(dimension="height"), ZoomInTool(), ZoomOutTool(), ResetTool(), UndoTool(), RedoTool(), SaveTool(), HelpTool(), CrosshairTool(), HoverTool()]
TOOLTIPS = [
    ("index", "$index"),
    ("Data point (x,y)", "Data point ($x, $y)"),
]
plot = figure(title="Filter data example (Original)", height=FIGURE_HEIGHT, width=FIGURE_WIDTH,  x_axis_label='x', y_axis_label='y', toolbar_location="left", tools=TOOLS_IN_CHART, tooltips=TOOLTIPS)

# Add some renderers with legend and line thickness to the plot
plot.scatter(x="x_values", y="y_values", size=20, source=SOURCE_1)
plot.line(x="x_values", y="y_values", color="red", line_width=2, source=SOURCE_2)

# plot.toolbar_location = None
plot.toolbar.autohide = True

# Similarly, use the logo property of the Toolbar to deactivate the Bokeh logo:
plot.toolbar.logo = None

"""
2. Filtering data
Bokeh comes with various filtering methods. Use these filters if you want to create a specific subset of the data contained in your ColumnDataSource.

In Bokeh, these filtered subsets are called "views". Views are represented by Bokeh's CDSView class.
To plot with a filtered subset of data, pass a CDSView object to the view argument of your renderer.

A CDSView object has one property:
- filter: an instance of Filter models

The simplest filter is the IndexFilter.
An IndexFilter uses a list of index positions and creates a view that contains nothing but the data points located at those index positions.

For example, if your ColumnDataSource contains a list of five values and you apply an IndexFilter with [0,2,4], the resulting view contains only the first, the third, and the fifth value of your riginal list.
"""
VIEW = CDSView(filter=IndexFilter([0, 2, 4]))
plot_filtered = figure(title="Filter data example (Filtered)", height=FIGURE_HEIGHT, width=FIGURE_WIDTH,  x_axis_label='x', y_axis_label='y', toolbar_location="left", tools=TOOLS_IN_CHART, tooltips=TOOLTIPS)
plot_filtered.scatter(x="x_values", y="y_values", size=20, source=SOURCE_1, view=VIEW)
plot_filtered.toolbar.autohide = True
plot_filtered.toolbar.logo = None

# Show both plots next to each other in a gridplot layout
show(gridplot([[plot, plot_filtered]]))
