import os
import datetime
import re
import random

weather_const = ['Snowy', 'Cloudy', 'Sunny', 'Overcast', 'Rainy', 'Foggy', 'Dusty', 'NULL']
windirection_const = ['North', 'East', 'South', 'West', 'Southeast', 'Northeast', 'Southwest', 'Northwest', 'NULL']
coff_weather = [50, 40, -60, 0, -50, 30, 55, 0]
coff_dir = [-30, 30, 0, 30, 30, -30, 20, 30, 0]
coff_speed = [0, -10, -40, -60, -70, -75, -80, -80, -90, -90, -65, -75]
coff_pressure_delta = [0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, -1, -1, -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, -1]

class Monitor:

	def __init__(self, date, time, AQIlevel, temperature, pressure, humidity, windspeed,
				 winddirection, weather):

		self.date = date
		self.time = int(time)
		self.AQIlevel = int(AQIlevel)
		self.temperature = float(temperature)
		self.pressure = int(pressure)
		self.humidity = int(humidity)
		self.speed = float(windspeed)
		self.direction = winddirection
		self.weather = weather

	def PrintData(self):
		print self.date, self.time, self.AQIlevel, self.temperature, self.pressure, self.humidity, self.speed\
			, self.direction, self.weather,

def get_weather(curweather):
	cnt = 0
	for weather in weather_const:
		if weather == curweather:
			return cnt
		cnt += 1
	return -1

def get_direction(direction):
	cnt = 0
	for direct in windirection_const:
		if direct == direction:
			return cnt
		cnt += 1
	return -1

def calc_speed(speed):
	if speed < 0:
		if speed == -3.5:
			return 10
		if speed == -4.5:
			return 11
		return -int(speed)
	if speed < 1: return 0
	if speed >= 1 and speed < 6: return 1
	if speed < 11 and speed >= 6: return 2
	if speed >= 11 and speed < 16: return 3
	if speed >= 16 and speed < 19: return 4
	if speed >= 19 and speed < 29 : return 5
	if speed >= 29 and speed < 39: return 6
	if speed >= 39 and speed < 50: return 7
	if speed >= 40 and speed < 50: return 8
	return 9

def calc_temper(temper):
	if temper <= 5:
		return -10
	if temper > 5 and temper <= 15:
		return 20
	return 30

def statbility(date, time, weather, direction, speed, temper, delta):
	kweather = 0.25
	kdirection = 0.1
	kspeed = 0.35
	ktemper = 0.2

	res = 0
	res += kweather * coff_weather[get_weather(weather)]
	res += kdirection * coff_dir[get_direction(direction)]
	res += kspeed * coff_speed[calc_speed(speed)]
	res += ktemper * calc_temper(temper)
	res += -delta * 100
	return int(res + 0.5)

def get_best_add():
	best_idx = 0
	best_value = 1000
	for begin in range(-50, 50):
		cnt = 0
		for i in range(n):
			if int((AQI_list[i] + begin) / 100 + 0.5) != the_list[i].AQIlevel:
				cnt += 1
		if cnt < best_value:
			best_value = cnt
			best_idx = begin
	return best_idx

def get_condition(x):
	level = int(x / 100 + 0.5)
	if level <= 1:
		return 'good'
	if level == 2:
		return 'normal'
	return 'bad'

os.chdir('/Users/cliente/Downloads/Air quality forecast/TestData')
dir_list = os.listdir(os.getcwd())

for FILE in dir_list:

	refind = re.findall(r'(.*?)\.csv', FILE)
	if refind == []:
		continue

	reader = open(FILE, 'r')
	filename = refind[0]
	AQI_list = []
	the_list = []

	for ttt in range(63):
		n = 4
		the_list = []
		for i in range(n):
			data, tmp = reader.readline().strip().split(' ')
			args = tmp.split(',')
			for i in range(len(args) - 2):
				if args[i] == 'NULL': args[i] = 0
			the_list.append(Monitor(data, *args))
		curAQI = the_list[0].AQIlevel * 100 + random.randint(-50, 50)
		now = the_list[0].pressure
		curtime = the_list[0].time
		AQI_list = []


		nowtime = datetime.datetime.strptime(the_list[0].date + '-' + str(the_list[0].time), "%Y-%m-%d-%H")
		for i in range(n):
			add = statbility(the_list[i].date, the_list[i].time, the_list[i].weather,
			                 the_list[i].direction, the_list[i].speed, the_list[i].temperature, the_list[i].pressure - now)
			curAQI += add
			curAQI = max(curAQI, 0)
			#the_list[i].PrintData()
			#print "AQI = %d" % curAQI
			AQI_list.append(curAQI)
			now = the_list[i].pressure
			curtime = (curtime + 1) % 24
			nowtime = nowtime + datetime.timedelta(hours=1)

		tmpargs = reader.readline().strip().split(',')
		args = []
		for i in tmpargs:
			if i != 'NULL': args.append(i)

	#	curAQI += get_best_add()
		good = 0
		bad = 0
		normal = 0
		for tt in range(12):

			writer = open(os.path.join('out','%d-%02d-%02d %02d'%(nowtime.year, nowtime.month, nowtime.day, nowtime.hour)), 'a')
			add = statbility(the_list[n-1].date, curtime, args[3], random.randint(0, 8), -float(args[2]), int(args[1]), coff_pressure_delta[curtime])
			curAQI += add
			curAQI = max(0, curAQI)
			writer.writelines(filename + ',' + str(curAQI))
			writer.writelines('\n')
			curtime = (curtime + 1) % 24
			nowtime = nowtime + datetime.timedelta(hours=1)
			writer.close()

		reader.readline()


