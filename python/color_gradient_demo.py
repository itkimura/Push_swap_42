from term_printer import ColorRGB, cprint

STEP = 8

for r in reversed(range(0, 256, STEP)):
    b = 255 - r
    for g in range(0, 256, STEP):
        cprint(" " * 4, attrs=[ColorRGB(r, g, b, is_bg=True)], end="")
        print('STEP = %d r = %d b = %d g = %d' % (STEP, r, b, g));

r = 248;
b = 7;
g = 248;

for i in range(31):
    cprint("  " * i, attrs=[ColorRGB(r, g, b, is_bg=True)], end="\n")
    g-= 8;

