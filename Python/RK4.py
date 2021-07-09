import pandas as pd
from IPython.display import display
# ============================================================================
# Only Change stuff below this line


def f(x, y):
    # change the return statement below to be the ODE
    return 3 * (x**2) * y


x0 = 1
y0 = 2

xn = 10  # x0 <= x <= xn
numSteps = 100

# Only change stuff above this line
# ============================================================================

yArray = [y0]
xArray = [x0]
h = (xn - x0) / numSteps


def k1(x, y, h):
    return f(x, y)


def k2(x, y, h):
    return f(x + h/2, y+h/2 * k1(x, y, h))


def k3(x, y, h):
    return f(x+h/2, y+h/2 * k2(x, y, h))


def k4(x, y, h):
    return f(x+h, y+h*k3(x, y, h))


def T4(x, y, h):
    return (1/6) * (k1(x, y, h) + 2*k2(x, y, h) + 2*k3(x, y, h) + k4(x, y, h))


for i in range(numSteps):
    yArray.append(yArray[i] + h * T4(xArray[i], yArray[i], h))
    xArray.append(xArray[i] + h)

dict = {'x': xArray, 'y': yArray}

df = pd.DataFrame(dict)

display(df)
