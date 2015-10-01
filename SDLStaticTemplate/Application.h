#pragma once
#include <SDL.h>
#include <string>

class Application
{
private:
    //Main loop flag
    bool quit;

    //The window
    SDL_Window* window;

    //The window renderer
    SDL_Renderer* renderer;

    // Window properties
    std::string title;
    unsigned int windowWidth;
    unsigned int windowHeight;
    bool isFullscreen;

    bool init();
    void close();
    void draw(SDL_Renderer* renderer);

public:
    Application();
    Application(std::string title);
    Application(std::string title, unsigned int width, unsigned int height, bool fullscreen);
    ~Application();

    void Run();
};