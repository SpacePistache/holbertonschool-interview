#!/usr/bin/python3


def canUnlockAll(boxes):
	for box in boxes:
		if box == [0] in boxes:
			print(boxes)
