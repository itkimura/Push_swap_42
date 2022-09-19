#import pygame as pg
import pygame as pg

#initiarize pygame
pg.init()

#screen setting ((width, height)) & caption
screen = pg.display.set_mode((500, 400))
pg.display.set_caption("bubble sort")

#initial position
x = 40
y = 40

#width and height of each bar
height = 20
width = [200, 50, 130, 90, 250, 61, 110, 88, 33, 80, 70, 159, 180, 20]
run = True

#method to show the list of height
def show(height):
	#drawing each item of list
	for i in range(len(height)):
		#draw a rectangle, (surface, color, position & dimention, x, y, width, height
		pg.draw.rect(screen, (255, 0, 0), (y + 30 * i, , width[i], height));

	#infinite loop
while run:
	#execute flag to start sorting
	execute = False
	#time delay
	pg.time.delay(10)
	#getting kets pressed
	keys = pg.key.get_pressed()

	for event in pg.event.get():
		if event.type == pg.QUIT:
			run = False

	if keys[pg.K_SPACE]:
		execute = True
	if execute == False:
		screen.fill((0, 0, 0))
		show(height)
		pg.display.update()
	else:
		for i in range(len(height) - 1):
			for j in range(len(height) - i - 1):
				if height[j] > height[j + 1]:
					tmp = height[j]
					height[j] = height[j + 1]
					height[j + 1] = tmp
			screen.fill((0, 0, 0))
			show(height)
			pg.time.delay(50)
			pg.display.update()
pg.quit()
