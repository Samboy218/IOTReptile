#! /usr/bin/env python3
import matplotlib
import matplotlib.pyplot as plt
import datetime
import sys

if (len(sys.argv) < 3):
    exit()
filename = sys.argv[1]
field_to_plot = int(sys.argv[2])
#we can only plot field 2 or 3
if (field_to_plot != 2) and (field_to_plot != 3):
    exit()

field_names = ["Time", "Sensor No.", "Humidity", "Temperature"]

times = []
temps = []
with open(filename, "r") as f:
    for line in f:
        times.append(datetime.datetime.fromtimestamp(int(line.split(", ")[0])))
        temps.append(float(line.split(", ")[field_to_plot]))

pltTimes = matplotlib.dates.date2num(times)
plt.figure(figsize=(10,5), dpi=100)
plt.plot_date(pltTimes, temps, fmt="g-")
plt.xlabel(field_names[0])
plt.ylabel(field_names[field_to_plot])
plt.xlim(pltTimes[0], pltTimes[-1])
plt.savefig("{}-{}.png".format(filename.split('.')[0], field_names[field_to_plot]), bbox_inches="tight")
