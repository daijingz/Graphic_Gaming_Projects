import pygame
from pygame.locals import *

pygame.init()

screen = pygame.display.set_mode([900, 600])

Red = (255, 0, 0)
Green = (0, 255, 0)
Blue = (0, 0, 255)

font1 = pygame.font.SysFont('didot.ttc', 48)

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((255, 255, 255))

    text = 'Find Same Shapes'
    img = font1.render(text, True, Red)
    screen.blit(img, (20, 20))

    pygame.draw.ellipse(screen, Red, (72, 179, 120, 92))
    pygame.draw.rect(screen, Green, (395, 200, 50, 50))
    pygame.draw.circle(screen, Blue, (675, 250), 100)

    pygame.display.flip()

pygame.quit()