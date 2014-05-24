import pdb
weather_const = ['Snowy', 'Cloudy', 'Sunny', 'Overcast', 'Rainy', 'Foggy', 'Dusty', 'NULL']
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
			, self.winddirection, self.weather

def printfloat(x):
	print "%.3f" % x,
reader = open('in','r')
station_condition = []
while True:
	line = reader.readline()
	if line == '':
		break
	data, tmp = line.strip().split(' ')
	args = tmp.split(',')
	if args[1] == 'NULL': continue
	if args[3] == 'NULL': continue
	station_condition.append(Monitor(data, *args))

def get_condition(x):
	if x <= 1:
		return 'Good'
	if x == 2:
		return 'Normal'
	return 'Bad'

def get_weather(curweather):
	cnt = 0
	for weather in weather_const:
		if weather == curweather:
			return cnt
		cnt += 1
	return -1


bad = 0
good = 0
normal = 0
cnt_good = [0 for i in range(8)] 
cnt_bad = [0 for i in range(8)]
cnt_normal = [0 for i in range(8)]
for station in station_condition:
#	station.PrintData()
	condition = get_condition(station.AQIlevel)
	if condition == 'Good':
		good += 1
		cnt_good[get_weather(station.weather)] += 1

	if condition == 'Normal':
		normal += 1
		cnt_normal[get_weather(station.weather)] += 1
	if condition == 'Bad':
		bad += 1
		cnt_bad[get_weather(station.weather)] += 1

#pdb.set_trace()
total = bad + normal + good + 0.0

print bad / total, normal / total, good / total

for i in cnt_good:
	printfloat (i / total)
print

for i in cnt_normal:
	printfloat (i / total)
print

for i in cnt_bad:
	printfloat (i / total)
print
