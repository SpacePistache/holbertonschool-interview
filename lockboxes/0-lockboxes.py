#!/usr/bin/python3
"""A small script determining if all boxes (list of lists) can be opened"""


def canUnlockAll(boxes):
    unlocked_box = [0]
    checked_boxes = [0]
    while checked_boxes:
        current_box = checked_boxes.pop()
        for box in boxes[current_box]:
            if box < len(boxes) and box not in unlocked_box:
                unlocked_box.append(box)
                checked_boxes.append(box)
    if len(unlocked_box) == len(boxes):
        return True
    else:
        return False
