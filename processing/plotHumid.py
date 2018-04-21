import matplotlib
import matplotlib.pyplot as plt
import datetime

times = []
humid = []
with open("dhtd.log", "r") as f:
    for line in f:
        times.append(datetime.datetime.fromtimestamp(int(line.split(", ")[0])))
        humid.append(float(line.split(", ")[2]))

pltTimes = matplotlib.dates.date2num(times)
plt.plot_date(pltTimes, humid, fmt="b-")
plt.xlabel("Time")
plt.ylabel("Humidity (%)")
plt.xlim(pltTimes[0], pltTimes[-1])
plt.show()
