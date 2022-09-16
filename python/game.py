import pygame as pg
import subprocess
import sys

# pygame.init() will initialize all
# imported module
pg.init()
clock = pg.time.Clock()

# it will display on screen
screen = pg.display.set_mode((1200, 1000))

# basic font for user typed
font = pg.font.Font(None, 32)

# create rectangle
input_rect = pg.Rect(200, 200, 140, 32)

#PUSH_SWAP = './push_swap'
#args = '10 9 8 7 6 5 4 3 2 1'
#data = subprocess.Popen([PUSH_SWAP, args], stdout=subprocess.PIPE)
#output = data.stdout.read()
#data.stdout.close()
#output = list(output.decode("utf-8").split("\n"))
#output.pop()
#print("---stdout---")
#print(output)
#pg.display.set_caption('itkimura push_swap visualizer')
while True:
    
    for event in pg.event.get():
        if event.type == pg.QUIT:
            pg.quit()
            sys.exit()


