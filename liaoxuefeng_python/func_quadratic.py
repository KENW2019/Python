import math


def quadratic(a, b, c):
    if not isinstance(a, (int, float)):
        raise TypeError(" a is not int or float")
    if not isinstance(b, (int, float)):
        raise TypeError(" b is not int or float")
    if not isinstance(c, (int, float)):
        raise TypeError(" c is not int or float")

    x = (b * b) - (4 * a * c)
    if x < 0:
        raise TypeError(" b^2-4ac is a negtive number")
    y = math.sqrt(x)
    return (-b + y) / (2 * a), (-b - y) / (2 * a)


