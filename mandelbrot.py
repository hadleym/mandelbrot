import numpy as np
import matplotlib.pyplot as plt


def mandelbrot_set(params, filename='mandelbrot_set.png'):
    x_min = params['x_min']
    x_max = params['x_max']
    y_min = params['y_min']
    y_max = params['y_max']
    width = params['width']
    height = params['height']
    max_iter = params['max_iter']

    image = np.zeros((height, width))
    for py in range(height):
        for px in range(width):
            x0 = x_min + (x_max - x_min) * px / (width - 1)
            y0 = y_min + (y_max - y_min) * py / (height - 1)
            x = 0
            y = 0
            iteration = 0
            while x * x + y * y < 4 and iteration < max_iter:
                x_temp = x * x - y * y + x0
                y = 2 * x * y + y0
                x = x_temp
                iteration += 1
            if iteration == max_iter:
                image[py, px] = 0  # Black for points inside the set
            else:
                image[py, px] = iteration / max_iter  # Color based on iteration count

    plt.imshow(image, cmap='hot', extent=(x_min, x_max, y_min, y_max))
    plt.colorbar()
    plt.title('Mandelbrot Set')
    plt.xlabel('Real')
    plt.ylabel('Imaginary')
    plt.savefig(filename)


parameters = {'x_min': -2, 'x_max': 2, 'y_min': -2, 'y_max': 2, 'width': 800, 'height': 800, 'max_iter': 50}
mandelbrot_set(parameters, 'm_' + str(parameters['max_iter']) + '.png')
