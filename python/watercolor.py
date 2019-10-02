##############
# Created by Eric Davidson: https://github.com/erdavids
#
# Inspired by this article: https://tylerxhobbs.com/essays/2017/a-generative-approach-to-simulating-watercolor-paints
#
# This script uses the pycairo graphics library to create watercolor styled images
##############



import cairo, sys, argparse, copy, math, random

float_gen = lambda a, b: random.uniform(a, b)

colors = []
for i in range(15):
    colors.append((float_gen(.4, .75), float_gen(.4, .75), float_gen(.4, .75)))

def octagon(x_orig, y_orig, side):
    x = x_orig
    y = y_orig
    d = side / math.sqrt(2)

    oct = []

    oct.append((x, y))

    x += side
    oct.append((x, y))

    x += d
    y += d
    oct.append((x, y))

    y += side
    oct.append((x, y))

    x -= d
    y += d
    oct.append((x, y))

    x -= side
    oct.append((x, y))

    x -= d
    y -= d
    oct.append((x, y))

    y -= side
    oct.append((x, y))

    x += d
    y -= d
    oct.append((x, y))

    return oct

def deform(shape, iterations, variance):
    for i in range(iterations):
        for j in range(len(shape)-1, 0, -1):
            midpoint = ((shape[j-1][0] + shape[j][0])/2 + float_gen(-variance, variance), (shape[j-1][1] + shape[j][1])/2 + float_gen(-variance, variance))
            shape.insert(j, midpoint)
    return shape


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--width", default=1000, type=int)
    parser.add_argument("--height", default=1500, type=int)
    parser.add_argument("-i", "--initial", default=120, type=int)
    parser.add_argument("-d", "--deviation", default=50, type=int)
    parser.add_argument("-bd", "--basedeforms", default=1, type=int)
    parser.add_argument("-fd", "--finaldeforms", default=3, type=int)
    parser.add_argument("-mins", "--minshapes", default=20, type=int)
    parser.add_argument("-maxs", "--maxshapes", default=25, type=int)
    parser.add_argument("-sa", "--shapealpha", default=.02, type=float)
    args = parser.parse_args()

    width, height = args.width, args.height
    initial = args.initial
    deviation = args.deviation

    basedeforms = args.basedeforms
    finaldeforms = args.finaldeforms

    minshapes = args.minshapes
    maxshapes = args.maxshapes

    shapealpha = args. shapealpha

    ims = cairo.ImageSurface(cairo.FORMAT_ARGB32, width, height)
    cr = cairo.Context(ims)

    cr.set_source_rgb(.9, .9, .9)
    cr.rectangle(0, 0, width, height)
    cr.fill()

    cr.set_line_width(1)

    for p in range(-int(height*.2), int(height*1.2), 60):
        cr.set_source_rgba(random.choice(colors)[0], random.choice(colors)[1], random.choice(colors)[2], shapealpha)

        shape = octagon(random.randint(-100, width+100), p, random.randint(100, 300))
        baseshape = deform(shape, basedeforms, initial)

        for j in range(random.randint(minshapes, maxshapes)):
            tempshape = copy.deepcopy(baseshape)
            layer = deform(tempshape, finaldeforms, deviation)

            for i in range(len(layer)):
                cr.line_to(layer[i][0], layer[i][1])
            cr.fill()

    ims.write_to_png('Examples/watercolor' + str(int(random.randint(0, 500))) + '.png')

if __name__ == "__main__":
    main()

