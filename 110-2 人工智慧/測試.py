def state_legal(x, y, b):
    if x < 0 or y < 0 or x > 3 or y > 3:
        return False
    if y < x and y > 0:
        return False
    elif (3-y) < 3-x and 3-y > 0:
        return False
    else:
        return True
def act_legal(x, y, b, xx, yy, bb):
    if b != bb:
        return False
    if b == 0 and state_legal(x - xx, y - yy, 1 - b):
        return True
    elif b == 1 and state_legal(x + xx, y + yy, 1 - b):
        return True
    else:
        return False
#when calling f, (x,y,b) is ensured to be state_legal
def f(x,y,b):
    for act in actions:
        if act_legal(x, y, b, act[0], act[1], act[2]):
            if act[2] == 0:
                print(x,y,b,"---",act, '---', x - act[0], y - act[1], 1 - b)
            else:
                print(x,y,b,"---",act, '---', x + act[0], y + act[1], 1 - b)
a = (0,1,2,3)
actions = []
for b in (0,1):
    for x in (0,1,2):
        for y in (0,1,2):
            if x + y >= 1 and x + y <= 2:
                actions.append((x,y,b))
print(actions)

for x in a:
    for y in a:
        for b in (0,1):
            if not(x == 0 and y == 0) and state_legal(x, y, b):
                f(x,y,b)




#x is num of savages, y is num of missionaries