#!/usr/bin/python3
"""A small script determining if all boxes can be opened"""

def canUnlockAll(boxes):
	for box in boxes:
		if box == [0] in boxes:
			print(boxes)
