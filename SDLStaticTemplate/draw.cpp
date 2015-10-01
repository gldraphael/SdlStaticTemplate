#include "Application.h"

#include <SDL.h>

#include <cmath>
#include <cstdio>


// helper function
int sign(float args)
{
    if (args < 0)
        return -1;
    else if (args > 0)
        return 1;
    else return 0;
}


// Performs the drawing
void Application::draw(SDL_Renderer* renderer)
{
    // Draws a line using a simple Line Drawing Algorithm

    // setting start and end co-ordinates for the points
    int x = 0, 
        y = 0, 
        x1 = windowWidth / 2, 
        y1 = windowHeight;

    // calculating the length
    float l = abs(x1 - x) > abs(y1 - y) ? abs(x1 - x) : abs(y1 - y);

    float dx = (x1 - x) / l;
    float dy = (y1 - y) / l;

    float xinc = x + 0.5 * sign(dx);
    float yinc = y + 0.5 * sign(dy);

    // Set Draw color (rgba) to Red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    for (int i = 0; i <= l; i++)
    {
        SDL_RenderDrawPoint(renderer, abs(xinc), abs(yinc));
        xinc = abs(xinc + dx);
        yinc = abs(yinc + dy);
    }
}