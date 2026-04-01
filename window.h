

//importers//
#pragma once
#include<SDL3/SDL_opengl.h>
#include<SDL3/SDL.h>
#define crewin(title,w, h, flags) SDL_CreateWindow(title,w, h, flags)
#define win SDL_Window
#define th SDL_Thread
#define e SDL_Event
#define kill(ptr_window_t) SDL_DestroyWindow(ptr_window_t)
#define exit() SDL_Quit()
#define creth(thread_func,b) SDL_CreateThread(thread_func,b)
#define delay(ms) SDL_Delay(ms)
#define FPS_MODE(win) \
    SDL_HideCursor(); \
    SDL_SetWindowRelativeMouseMode(win,1);
#define UI_MODE(win) \
    SDL_ShowCursor(); \
    SDL_SetWindowRelativeMouseMode(win, 0);
#define init() SDL_Init(SDL_INIT_EVENTS|SDL_INIT_VIDEO);\
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);\
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);\
    SDL_GL_SetSwapInterval(1);


//funcs//

typedef struct w_t{
win *window_hand;
e event;
SDL_GLContext context;
}win_t;

