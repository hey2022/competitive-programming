width, m, n = [int(i) for i in input().split()]


def get_pos(n, width):
    current_width = width
    direction = "decrease"
    y = 1
    remaining = n

    while True:
        if remaining <= current_width:
            row_direction = "left-right" if y % 2 == 1 else "right-left"
            if row_direction == "left-right":
                x = remaining
            else:
                x = current_width - remaining + 1
            return (x, y)
        else:
            remaining -= current_width
            y += 1
            if direction == "decrease":
                current_width -= 1
                if current_width == 1:
                    direction = "increase"
            else:
                current_width += 1
                if current_width == width:
                    direction = "decrease"


def manhattan_distance(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


print(manhattan_distance(get_pos(m, width), get_pos(n, width)))
