import pygame as pg
import subprocess
import sys

# pygame.init() will initialize all
# imported module

WIDTH = 800
HEIGHT = 600
BLACK = (0, 0, 0)
WHITE = (255, 255, 255) 

def main():
	open()

def open():
# it will display on screen
	pg.init()
#set clock time
	clock = pg.time.Clock()
# basic font for user typed
	font = pg.font.Font(None, 32)
#surface setting
	screen = pg.display.set_mode((1600, 900))
#caption for screen
	pg.display.set_caption("itkimura push_swap visualizer")
	x = 50
	y = 450
	width = 40
	height = 60
	vel = 5
	isJump = False
	jumpCount = 10
	while True:
		pg.time.delay(100)

		keys = pg.key.get_pressed()
		if keys[pg.K_LEFT] and x > vel:
			x -= vel
		if keys[pg.K_RIGHT] and x < 1600 - width - vel:
			x += vel
		if not (isJump):
			if keys[pg.K_UP] and y > vel:
				y -= vel
			if keys[pg.K_DOWN] and y < 900 - height - vel:
				y += vel
			if keys[pg.K_SPACE]:
				isJump =True
		else:
			if jumpCount >= -10:
				neg = 1
				if jumpCount < 0:
					neg = -1;
				y -= (jumpCount ** 2) / 2 * neg
				jumpCount -= 1
			else:
				isJump = False
				jumpCount = 10

		screen.fill((0 ,0 ,0))
		pg.draw.rect(screen, (255, 0, 0), (x, y, width, height))
		pg.display.update()
		for event in pg.event.get():
			if event.type == pg.QUIT:
				pg.quit()
				sys.exit()

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

if __name__=="__main__":
    main()


