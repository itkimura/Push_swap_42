import pygame as pg
import math
import sys

#initial position
x = 40
y = 40
SCREEN_WIDTH = 950
SCREEN_HEIGHT = 580
#screen setting ((width, height)) & caption
screen = pg.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pg.display.set_caption("itkimura push_swap visualizer")


#width and height of each bar
height = 20
value = [200, 50, 130, 90, 250, 61, 110, 88, 33, 80, 70, 159, 180, 20, 2000]

def stack_print(value):
    height = math.floor((SCREEN_HEIGHT - 150)  / len(value));
    for i in range(len(value)):
        #draw a rectangle, (surface, color, position & dimention, x, y, width, height
        pg.draw.rect(screen, (255, 0, 0), (30, 120 + (height * i), value[i], height));

def main():
    pg.init()
    while True:

        execute = False
        
        keys = pg.key.get_pressed()
        if keys[pg.K_SPACE]:
            execute = True
        if execute == False:
           # screen.fill((0, 0, 0))
            stack_print(value)
            pg.display.update()
        for event in pg.event.get():
            if event.type == pg.QUIT:
                pg.quit()
                sys.exit()
        #fill background color
        screen.fill((0, 0, 0))
        #title
        font = pg.font.SysFont('Futura', 25);
        text = font.render("itkimura push_swap visualizer", True, (255,255,255));
        text_rect = text.get_rect(center=(SCREEN_WIDTH/2, 30))
        screen.blit(text, text_rect)
        
        #stack_a
        font = pg.font.SysFont('Futura', 20);
        a_text = font.render("stack_a", True, (255,255,255));
        screen.blit(a_text, [30, 60])

        #stack_b
        b_text = font.render("stack_b", True, (255,255,255));
        screen.blit(b_text, [(SCREEN_WIDTH - 190) / 2, 60])
        
        #ops
        b_text = font.render("ops", True, (255,255,255));
        screen.blit(b_text, [SCREEN_WIDTH - 130, 60])
        stack_print(value)
        pg.display.update()

if __name__ == "__main__":
    main()
