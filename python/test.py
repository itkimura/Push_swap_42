import pygame as pg
from term_printer import ColorRGB, cprint
import math
import sys
sys.path.insert(0, '.')
from config import PUSH_SWAP, CHECKER, NB, DELAY_TIME

#initial position
x = 40
y = 40
SCREEN_WIDTH = 950
SCREEN_HEIGHT = 580
#30 + 365 + 30 + 365 + 30 +  100 + 30
bar = 365
margin = 30

#screen setting ((width, height)) & caption
screen = pg.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pg.display.set_caption("itkimura push_swap visualizer")


#width and height of each bar
value = [200, 50, 130, 90, 250, 61, 110, 88, 33, 80, 70, 159, 180, 20, 2000, 40]
#value = [200, 50, 130, 90, 250]

#color
r = 248;
b = 7;
g = 248;

def init_width(value):
    newlist = sorted(value)
    for i in range(len(value)):
        for j in range(len(newlist)):
            if value[i] == newlist[j]:
                value[i] = j + 1

def stack_print(value):
    height = math.floor((SCREEN_HEIGHT - 150)  / len(value));
    init_width(value);
    size = bar / len(value);
    for i in range(len(value)):
        #draw a rectangle, (surface, color, position & dimention, x, y, width, height
        pg.draw.rect(screen, (r, g - (8 * value[i]) , b), (30, 120 + (height * i), int(size) * value[i], height));

def input():
    print("hello world")

def main():
    pg.init()
    print(NB);
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
        screen.blit(b_text, [bar + 60, 60])
        
        #ops
        b_text = font.render("ops", True, (255,255,255));
        screen.blit(b_text, [SCREEN_WIDTH - 130, 60])
        stack_print(value)
        pg.display.update()

if __name__ == "__main__":
    main()
