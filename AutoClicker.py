# This autoclicker was designed to work with
# AFK Fish Farming in Minecraft
# To use:
#   Pause Minecraft
#   Run this script
#   Unpause Minecraft
#   Press 'F10' and AFK fish farm
#   Hold 'F10' again to end script

import keyboard
import mouse
import time


keyboard.wait('F10')
time.sleep(1.5)
while(True):
        if keyboard.is_pressed('F10'):
                break
        else:
                time.sleep(.4)
                mouse.right_click()
