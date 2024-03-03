from gpiozero import LED
import time

reds = LED(14)
blues = LED(15)

while True:
	blues.on()
	reds.on()
	print("Growlights Active")
	time.sleep(16)
	blues.off()
	reds.off()
	print("Growlights Inactive")
	time.sleep(8)
