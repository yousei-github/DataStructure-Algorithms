# 7_time_chart.py
"""Time chart."""

import random
from datetime import datetime, timedelta

import platform

# Bokeh
from bokeh.plotting import *
from bokeh.models import DatetimeTickFormatter, NumeralTickFormatter

# Check python version requirement of Bokeh
PYTHON_VERSION = list(map(int, platform.python_version_tuple()))
if PYTHON_VERSION < [3, 10, 0]:
    print("Error: Running Python below 3.10.0, current is " + str(PYTHON_VERSION))
    exit(1)

"""
1. Creating a time chart

Apply theme to current document.
Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
"""
curdoc().theme = "caliber"

# Prepare data:
NUMBER_OF_DAY_IN_A_MONTH = 31
DATES = [(datetime.now() + timedelta(day * 7)) for day in range(0, NUMBER_OF_DAY_IN_A_MONTH)]  # Generate list of dates (today's date in subsequent weeks)
LOWEST_INCOME = 0
HIGHEST_INCOME = 500
Y_DATA = random.sample(range(LOWEST_INCOME, HIGHEST_INCOME), NUMBER_OF_DAY_IN_A_MONTH)  # Generate [NUMBER_OF_DAY_IN_A_MONTH] random data points

"""
2. Vectorizing colors and sizes
- To change colors depending on values in a variable, pass a variable containing color information to the color attribute
- To create a plot with sizes in relation to your data, apply the same principle to the radius (or size) argument of your renderer
"""
COLORS = [f"#{255:02x}{int((value * 255) / 100):02x}{255:02x}" for value in Y_DATA]
RADII = [value / 5 for value in Y_DATA]

"""
3. Enabling datetime axes
Set the x_axis_type or y_axis_type to datetime to display date or time information on an axis

Create a new plot with a title, size (Responsive plot sizing), axis labels, and axis type
"""
plot = figure(title="Time example", sizing_mode="stretch_width",  x_axis_label='Date', y_axis_label='Average Income', x_axis_type="datetime")

# Add some renderers with legend and line thickness to the plot
plot.scatter(DATES, Y_DATA, fill_color=COLORS, line_color="blue", size=RADII)
plot.line(DATES, Y_DATA, color="navy", line_width=1)

# Format axes ticks
plot.xaxis[0].formatter = DatetimeTickFormatter(months="%b %Y")
plot.yaxis[0].formatter = NumeralTickFormatter(format="$0.00")

# Show the results
show(plot)
