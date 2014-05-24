import os
import random

weather_const = ['Snowy', 'Cloudy', 'Sunny', 'Overcast', 'Rainy', 'Foggy', 'Dusty', 'NULL']
weather_increasing_const = [5, 5, 5, 5, -10, 10, 15, 0]
winddirection_const = ['North', 'East', 'South', 'West', 'Southeast', 'Northeast', 'Southwest', 'Northwest', 'NULL']
winddirection_k_const = [-3.5, 0, -0.1, 0.1, 0.2, -3.5, 1, -0.5, 0.2]
# 24-hours increasing const
time_increasing_const = [-5, -5, -5, -5, -5, 0, 0, 0, 5, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0]

class Monitor:

	def __init__(self, date, time, AQIlevel, temperature, pressure, humidity, windspeed,
				 winddirection, weather):

		self.date = date
		self.time = int(time)
		self.AQIlevel = int(AQIlevel)
		self.temperature = float(temperature)
		self.pressure = int(pressure)
		self.humidity = int(humidity)
		self.windspeed = float(windspeed)
		self.winddirection = winddirection
		self.weather = weather

	def PrintData(self):
		print self.date, self.time, self.AQIlevel, self.temperature, self.pressure, self.humidity, self.windspeed\
			, self.winddirection, self.weather,

def get_weather(curweather):
	cnt = 0
	for weather in weather_const:
		if weather == curweather:
			return cnt
		cnt += 1
	return -1

filename = 'in'
reader = open(filename, 'r')

station_condition = []
def get_k(direction):
	cnt = 0
	for direct in winddirection_const:
		if direct == direction:
			break
		cnt += 1
	return winddirection_k_const[cnt]

def stable_coeff(temperature, humidity, windspeed):
	return (-(temperature - 5) - windspeed * humidity / 100.)

def get_condition(x):
	if x <= 1:
		return 'Good'
	if x == 2:
		return 'Normal'
	return 'Bad'
def get_speed(force):
	if force == '3':
		return random.randint(3, 19)
	if force == '4':
		return random.randint(20, 29)
	if force == '5':
		return random.randint(30, 44)
	if force == '3.5':
		return random.randint(17, 23)
	if force == '4.5':
		return random.randint(27, 33)

def get_AQIlist(begin_const, force, winddirection, weather, temperature):
	curtime = station_condition[0].time
	curdate = station_condition[0].date
	curweather = get_weather(station_condition[0].weather)
	curAQI = station_condition[0].AQIlevel * 100 - 25 + begin_const

	curlist = []
	for i in range(n):
		k = get_k(station_condition[i].winddirection)
		curAQI += time_increasing_const[curtime] + weather_increasing_const[curweather] + \
		          int(station_condition[i].windspeed*3)
		curAQI += stable_coeff(station_condition[i].temperature, station_condition[i].humidity, station_condition[i].windspeed)
		curAQI = max(curAQI, 0)
		curlist.append(curAQI)

		if i + 1 == n: break
		curtime = (curtime + 1) % 24
		curweather = get_weather(station_condition[i+1].weather)

	curweather = get_weather(weather)
	windspeed = get_speed(force)
	for i in range(12):
		k = get_k(winddirection)
		curAQI += time_increasing_const[curtime] + weather_increasing_const[curweather] + \
		          int(windspeed*-random.randint(0,3))
		curAQI += stable_coeff(temperature, station_condition[n-1].humidity, windspeed)
		curAQI = max(curAQI, 0)
		curlist.append(curAQI)
		curtime = (curtime + 1) % 24
	return curlist

force = 0
windirection = 0
temperature = 0
weather = ''
for k in range(1):
	for i in range(5):
		line = reader.readline()
		if line == '':
			break
		if i < 4:
			data, tmp = line.strip().split(' ')
			args = tmp.split(',')
			station_condition.append(Monitor(data, *args))
			continue
		data = line.strip().split(',')
		temperature = int(data[2])
		force = data[5]
		windirection = data[6]
		weather = data[7]


	n = len(station_condition)
	best_const = 0
	best_value = 1000

	for begin_const in range(-1000, 1000):
		curlist = get_AQIlist(begin_const, force, windirection, weather, temperature)
		cnt = 0
		for i in range(n):
			station = station_condition[i]
			if (station.AQIlevel) != (int(curlist[i] / 100. + 0.5)):
				cnt += 1
		if cnt == best_value and abs(begin_const) < abs(best_const):
			best_value = cnt
			best_const = begin_const
		if cnt < best_value:
			best_value = cnt
			best_const = begin_const

	print best_value, best_const
	best_list = get_AQIlist(best_const, force, windirection, weather, temperature)
	for i in range(n):
		station_condition[i].PrintData()
		print "AQI = %d AQIlevel = %d" % (best_list[i], int(best_list[i] / 100. + 0.5))
	for i in range(n, n + 12):
		print "AQI = %d AQIlevel = %s" % (best_list[i], get_condition(int(best_list[i] / 100. + 0.5)))