# 7_time_chart.py
"""Time chart."""

import random
from datetime import datetime, timedelta

# Bokeh
from bokeh.plotting import *
from bokeh.models import DatetimeTickFormatter, NumeralTickFormatter

# 1. Creating a time chart

# Apply theme to current document.
# Bokeh comes with five built-in themes: caliber, dark_minimal, light_minimal, night_sky, and contrast.
curdoc().theme = "caliber"

# Prepare data:
NUMBER_OF_DAY_IN_A_MONTH = 31
dates = [(datetime.now() + timedelta(day * 7)) for day in range(0, NUMBER_OF_DAY_IN_A_MONTH)]  # Generate list of dates (today's date in subsequent weeks)
LOWEST_INCOME = 0
HIGHEST_INCOME = 500
y = random.sample(range(LOWEST_INCOME, HIGHEST_INCOME), NUMBER_OF_DAY_IN_A_MONTH)  # Generate [NUMBER_OF_DAY_IN_A_MONTH] random data points

# Create a new plot with a title, size (Responsive plot sizing), axis labels, and axis type
# 2. Enabling datetime axes
# Set the x_axis_type or y_axis_type to datetime to display date or time information on an axis
plot = figure(title="Time example", sizing_mode="stretch_width",  x_axis_label='Date', y_axis_label='Average Income', x_axis_type="datetime")

# Add some renderers with legend and line thickness to the plot
plot.scatter(dates, y, size=8)
plot.line(dates, y, color="navy", line_width=1)

# Format axes ticks
plot.xaxis[0].formatter = DatetimeTickFormatter(months="%b %Y")
plot.yaxis[0].formatter = NumeralTickFormatter(format="$0.00")

# Show the results
show(plot)
