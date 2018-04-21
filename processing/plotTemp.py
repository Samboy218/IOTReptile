import matplotlib
import matplotlib.pyplot as plt
import datetime

times = []
temps = []
with open("dhtd.log", "r") as f:
    for line in f:
        times.append(datetime.datetime.fromtimestamp(int(line.split(", ")[0])))
        temps.append(1.8 * float(line.split(", ")[3]) + 32)

pltTimes = matplotlib.dates.date2num(times)
plt.plot_date(pltTimes, temps, fmt="g-")
plt.xlabel("Time")
plt.ylabel("Temp (F)")
plt.xlim(pltTimes[0], pltTimes[-1])
plt.show()
