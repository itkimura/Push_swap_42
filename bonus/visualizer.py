import pygame as pg
from term_printer import ColorRGB, cprint
import random
import subprocess
import sys
from config import PUSH_SWAP, CHECKER, MIN, MAX, NB_SIZE, DELAY_TIME
from operations import *

#initial position
x = 40
y = 40
SCREEN_WIDTH = 950
SCREEN_HEIGHT = 680

#30 + 365 + 30 + 365 + 30 +  100 + 30
GRAPH_WIDTH = 365
MARGIN = 30

#SCREEN setting ((width, height)) & caption
SCREEN= pg.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pg.display.set_caption("itkimura push_swap visualizer")

#random number
def random_ints_nodup(MIN, MAX, NB_SIZE):
    NB = []
    while len(NB) < NB_SIZE:
        N = random.randint(MIN, MAX)
        if not N in NB:
            NB.append(N)
    return NB

random = random_ints_nodup(MIN, MAX, NB_SIZE)

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
    return (NB)

def print_stack(stack_a, stack_b, ops, ops_nb):
    g = 248;
    height = (SCREEN_HEIGHT - 150)  / NB_SIZE;
    width = GRAPH_WIDTH / NB_SIZE;
    limit = len(stack_a)
    if (limit > 500):
        height = 1
        limit = 500
    for i in range(limit):
        #draw a rectangle, (surface, color, position & dimention, x, y, width, height
        g = 248 - (8 * (stack_a[i] / (NB_SIZE / 31)))
        pg.draw.rect(SCREEN, (r, g, b), (30, 120 + (int(height) * i), width * stack_a[i], height));
    limit = len(stack_b)
    if (limit > 500):
        height = 1
        limit = 500
    for i in range(limit):
        #draw a rectangle, (surface, color, position & dimention, x, y, width, height
        g = 248 - (8 * (stack_b[i] / (NB_SIZE / 31)))
        pg.draw.rect(SCREEN, (r, g, b), (60 + GRAPH_WIDTH, 120 + (int(height) * i), width * stack_b[i], height));
    args_len = len(ops)
    if args_len > 50:
        args_len = 50;
    for i in range(args_len):
        font = pg.font.SysFont('Futura', 10);
        ops_nb += 1
        ops_str = ' [ ' + str(ops_nb) + ' ]'
        text = font.render(ops_str, True, (255,255,255));
        text_rect = text.get_rect(center=(MARGIN * 3 + GRAPH_WIDTH * 2, (120 + (10 * i))))
        SCREEN.blit(text, text_rect)
        text = font.render(str(ops[i]), True, (255,255,255));
        text_rect = text.get_rect(center=(MARGIN * 3 + GRAPH_WIDTH * 2 + 30, (120 + (10 * i))))
        SCREEN.blit(text, text_rect)

def text():
    #title
    font = pg.font.SysFont('Futura', 20);
    text = font.render("[Press Sapce to start] itkimura push_swap visualizer", True, (255,255,255));
    text_rect = text.get_rect(center=(SCREEN_WIDTH/2, 30))
    SCREEN.blit(text, text_rect)

    #stack_a
    font = pg.font.SysFont('Futura', 20);
    a_text = font.render("stack_a", True, (255,255,255));
    SCREEN.blit(a_text, [MARGIN, 60])

    #stack_b
    b_text = font.render("stack_b", True, (255,255,255));
    SCREEN.blit(b_text, [GRAPH_WIDTH + MARGIN * 2, 60])

    #ops
    b_text = font.render("ops", True, (255,255,255));
    SCREEN.blit(b_text, [SCREEN_WIDTH - 130, 60])

def push_swap():
    random_str = [str(n) for n in random]
    args =  " ".join(random_str)
    data = subprocess.Popen([PUSH_SWAP, args], stdout=subprocess.PIPE)
    output = data.stdout.read()
    data.stdout.close()
    output = list(output.decode("utf-8").split("\n"))
    output.pop()
    return (output)

def main():
    pg.init()
    stack_a = init_width(random)
    stack_b = []
    output = push_swap()
    output_nb = 0
    execute = False
    while True:
        pg.time.delay(DELAY_TIME)
        keys = pg.key.get_pressed()
        print_stack(stack_a, stack_b, output, output_nb)
        pg.display.update()
        if keys[pg.K_SPACE]:
            execute = True
        if execute == True:
            if len(output) != 0:
                apply_ops(str(output[0]), stack_a, stack_b)
                output_nb += 1
                del output[0]
        for event in pg.event.get():
            if event.type == pg.QUIT:
                pg.quit()
                sys.exit()
        #fill background color
        SCREEN.fill((0, 0, 0))
        text()

if __name__ == "__main__":
    main()
