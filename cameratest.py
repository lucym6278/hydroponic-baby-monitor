from picamera import PiCamera
import time;
#import datetime

camera = PiCamera()
camera.resolution = (640, 480)

while True:
    camera.capture("/home/dragon/Desktop/website/camera/photos/latest.jpg")
    print("Photo Captured");
    time.sleep(300);
