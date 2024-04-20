import colorsys
from fcmega import FCMega

if __name__ == "__main__":

    fc_mega = FCMega()

    rainbow = [[int(v * 255) for v in colorsys.hsv_to_rgb((i / 400.0), 1.0, 0.5)] for i in range(400)]

    leds = [(0, 0, 0) for _ in range(400 * 24)]
    for i in range(400):

        for j in range(400):
            leds[j] = rainbow[(j + i) % 400]

        fc_mega.set_pixels(leds)
        fc_mega.update()
