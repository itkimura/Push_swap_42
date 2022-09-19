import pygame as py
import random
pg.init()


class DrowInformarion:
	BLACK = 0, 0, 0
	WHITE = 255, 255, 255
	GREEN = 0, 255, 0
	RED = 255, 0, 0
	GREY = 128, 128, 128
	BACKGROUND = WHITE
	SIDE_PAD = 100

	def __init__(self, width, height, lst):
		self.width = width
		self.height = height
		self.window = pg.display.set_mode((width, height))
		pg.display.set_caption("Sorting Algoright")
		self.set_list(lst)

	def set_list(self, lst):
		self.lst = lst
		self.min_val = min(lst)
		self.max_val = max(lst)
		self.pixcel_width = self.width - self.SIDE_PAD / len(lst)

