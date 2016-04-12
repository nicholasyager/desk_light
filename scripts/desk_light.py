#!/usr/bin/python3
"""desk_light

Usage:
    desk_light.py <light> <red> <green> <blue> [<effect>]
"""

import serial
import time
from docopt import docopt

class Strip:

    def __init__(self, num_lights):
        self.ser =  serial.Serial('/dev/ttyACM0', 9600, timeout=1)

        self.lights = []
        for _ in range(num_lights):
            self.lights.append([0,0,0,0])


    def color(self, light, red, green, blue):
        self.lights[light][0] = red
        self.lights[light][1] = green
        self.lights[light][2] = blue

    def alarm(self, light):
        self.lights[light][3] = 1

    def no_effect(self, light):
        self.lights[light][3] = 0

    def update(self, light):
        self.ser.write(bytes([light]+self.lights[light]))

def main(arguments):
    strip = Strip(3)
    if arguments["<effect>"] == "alarm":
        strip.alarm(int(arguments["<light>"]))
    if arguments["<effect>"] == "none":
        strip.no_effect(int(arguments["<light>"]))

    strip.color(int(arguments["<light>"]),
                int(arguments['<red>']),
                int(arguments['<green>']),
                int(arguments['<blue>']))
    strip.update(int(arguments["<light>"]))





if __name__ == "__main__":
    main(docopt(__doc__, version="NeoLight 0.1"))
