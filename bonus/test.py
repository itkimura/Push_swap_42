import pygame as pg
from term_printer import ColorRGB, cprint
import random
import sys
from config import PUSH_SWAP, CHECKER, MIN, MAX, NB_SIZE, DELAY_TIME

#initial position
x = 40
y = 40
SCREEN_WIDTH = 950
SCREEN_HEIGHT = 680

#30 + 365 + 30 + 365 + 30 +  100 + 30
GRAPH_SIZE = 365
MARGIN = 30

#SCREEN setting ((width, height)) & caption
SCREEN= pg.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pg.display.set_caption("itkimura push_swap visualizer")


#width and height of each GRAPH

#color
r = 248;
b = 7;

def init_width(NB):
    newlist = sorted(NB)
    for i in range(len(NB)):
        for j in range(len(newlist)):
            if NB[i] == newlist[j]:
                NB[i] = j + 1

def random_ints_nodup(MIN, MAX, NB_SIZE):
    NB = []
    while len(NB) < NB_SIZE:
        N = random.randint(MIN, MAX)
        if not N in NB:
            NB.append(N)
    return NB

def print_stack(NB):
    height = (SCREEN_HEIGHT - 150)  / len(NB);
    init_width(NB);
    size = GRAPH_SIZE / len(NB);
    limit = len(NB);
    g = 248;
    if (height < 1):
        height = 1;
        limit = SCREEN_HEIGHT - 150;
    for i in range(limit):
        #draw a rectangle, (surface, color, position & dimention, x, y, width, height
        each_color = limit / 31;
        if i % int(each_color) == 0 and g - 8 > 0:
            g -= 8
        pg.draw.rect(SCREEN, (r, g, b), (30, 120 + (int(height) * i), size * NB[i], height));

def text():
    #title
    font = pg.font.SysFont('Futura', 25);
    text = font.render("itkimura push_swap visualizer", True, (255,255,255));
    text_rect = text.get_rect(center=(SCREEN_WIDTH/2, 30))
    SCREEN.blit(text, text_rect)

    #stack_a
    font = pg.font.SysFont('Futura', 20);
    a_text = font.render("stack_a", True, (255,255,255));
    SCREEN.blit(a_text, [MARGIN, 60])

    #stack_b
    b_text = font.render("stack_b", True, (255,255,255));
    SCREEN.blit(b_text, [GRAPH_SIZE + MARGIN * 2, 60])

    #ops
    b_text = font.render("ops", True, (255,255,255));
    SCREEN.blit(b_text, [SCREEN_WIDTH - 130, 60])

def main():
    pg.init()
    NB = random_ints_nodup(MIN, MAX, NB_SIZE)
    while True:
        execute = False
        keys = pg.key.get_pressed()
        if keys[pg.K_SPACE]:
            execute = True
        if execute == False:
            print_stack(NB)
            pg.display.update()
        for event in pg.event.get():
            if event.type == pg.QUIT:
                pg.quit()
                sys.exit()
        #fill background color
        SCREEN.fill((0, 0, 0))
        text()

if __name__ == "__main__":
    main()
