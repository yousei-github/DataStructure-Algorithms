# 2_multi_line_chart.py
"""Multi-line chart."""

import sys
import platform
from pathlib import Path

# Bokeh
from bokeh.plotting import *

# Check python version requirement of Bokeh
PYTHON_VERSION = list(map(int, platform.python_version_tuple()))
if PYTHON_VERSION < [3, 10, 0]:
    print("Error: Running Python below 3.10.0, current is " + str(PYTHON_VERSION))
    exit(1)

"""
1. Creating multi-line chart

Apply theme to current document.
Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
"""
curdoc().theme = "caliber"

# Prepare data:
X_DATA = [1, 2, 3, 4, 5]
Y_LINE_1_DATA = [6, 7, 2, 4, 5]
Y_LINE_2_DATA = [2, 3, 4, 5, 6]
Y_LINE_3_DATA = [4, 5, 5, 7, 2]

# Create a new plot with a title, size (Responsive plot sizing), and axis labels
plot = figure(title="Multiple line example", sizing_mode="stretch_width", height=250, x_axis_label='x', y_axis_label='y')

# Add multiple renderers with legend and line thickness to the plot
plot.line(X_DATA, Y_LINE_1_DATA, legend_label="Line 1.", color="blue", line_width=2)
plot.line(X_DATA, Y_LINE_2_DATA, legend_label="Line 2.", color="red", line_width=2)
plot.line(X_DATA, Y_LINE_3_DATA, legend_label="Line 3.", color="green", line_width=2)

"""
2. Adding and styling a legend
Use the properties of the Legend object to customize the legend. For example:
(1) Display legend in top left corner (default is top right corner)
"""
plot.legend.location = "top_left"

# (2) Add a title to your legend
plot.legend.title = "Line Legend"

# (3) Change appearance of legend text
plot.legend.label_text_font = "times"
plot.legend.label_text_font_style = "italic"
plot.legend.label_text_color = "navy"

# (4) Change border and background of legend
plot.legend.border_line_width = 3
plot.legend.border_line_color = "navy"
plot.legend.border_line_alpha = 0.8
plot.legend.background_fill_color = "navy"
plot.legend.background_fill_alpha = 0.2

"""
3. Creating a standalone HTML file
The show() function saves your visualization to an HTML file.
This HTML file contains all the necessary information to display your plot.

To customize the file Bokeh creates for your visualization, import and call the output_file() function.
output_file() accepts various file-related arguments. For example:
- filename: the filename for the HTML file
- title: the title for you document (to be used in the HTML's <title> tag)

If you don't use the output_file() function to define a custom file name, Bokeh defaults to using the file name of the currently running Python script for the filename of the HTML output.
If a script filename is not available (for instance, in a Jupyter notebook), then Bokeh will generate a random filename.
"""
SYSTEM_NAME = platform.system()
path_separator = 0
if SYSTEM_NAME == "Windows":
    path_separator = '\\'
elif SYSTEM_NAME == "Linux":
    path_separator = '/'
else:
    print("Error: Unlnown OS")
    exit(1)

BASE_PATH = sys.argv[0].rsplit(path_separator, 1)[0]
PATH = Path(BASE_PATH).joinpath('2. Multiple line chart.html')
output_file(filename=PATH.absolute(), title="Multiple Line")

# Save the results to a file
save(plot)

# Show the results
# show(plot)
