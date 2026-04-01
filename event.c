


//IMPORTERS//
#include"window.h"
#include"event.h"
    extern bool runner;
    extern SDL_Mutex *keyboard_event_s;
    extern win_t window;
    extern SDL_Mutex *xyrot_s;
    extern GLfloat x,y,rot_x,rot_y;
    extern GLuint vbo;
    extern float vertices[27];
    extern GLfloat x2,y2,rot_x2,rot_y2;
    extern GLuint vbo2;
    extern float vertices2[27];
    extern bool e_runner;
    extern int sen;
//glob vars
    e keyboard_event;//  MAY CAUSE LINKAGE ERROR
    e ev;
//funcs//
static int mouseevent(void *hi){
while(e_runner){
switch (window.event.type) {

    case SDL_EVENT_MOUSE_MOTION:
    //x=((window.event.motion.x/600)-1)*sen;
    //y=((window.event.motion.y/(-250))+1)*sen;
    x2=x2+(((int)window.event.motion.xrel)*sen);//**MAY CAUSE SEMANTIC ERRORS**
    y2=y2+(((int)window.event.motion.yrel)*sen);//**MAY CAUSE SEMANTIC ERRORS**
    printf("x:%d\n",(int)window.event.motion.xrel);
    printf("y:%d\n",(int)window.event.motion.yrel);
    window.event.type=0;
    //add break
    //add mouse case
    }
    return 0;
}

}
/*static int keyboardevent(void *hi){
unsigned int current_key =(unsigned int) *hi;
while(e_runner){
SDL_LockMutex(keyboard_event_s);

switch(keyboard_event.key.key){
    case up:

    case down:

}
if(keyboard_event.type==0 && keyboard_event.key.key==current_key){
    return 0;
}
}
}*/
int event(void *hi){
    //alloc


while(e_runner){
    SDL_WaitEvent(&ev);

    switch (ev.type) {
    case SDL_EVENT_QUIT:
        printf("QUIT\n");
        e_runner=0;
        runner=0;
        break;
    case SDL_EVENT_MOUSE_MOTION://mouse_move updator
        //SDL_Thread *world__updater=SDL_CreateThread(world_updater,"world updater",NULL);//name conflict (segmentation fault)
        window.event.type=ev.type;
        window.event.motion.xrel=(int)ev.motion.xrel;
        window.event.motion.yrel=(int)ev.motion.yrel;
        SDL_CreateThread(mouseevent,"mouse event",NULL);
        break;
    case presseed:
        SDL_LockMutex(keyboard_event_s);
        keyboard_event=ev;
        SDL_UnlockMutex(keyboard_event_s);
        //SDL_CreateThread(keyboardevent,&keyboard_event.key.key);//only passing keys
        break;
    case released:
        SDL_LockMutex(keyboard_event_s);
        keyboard_event=ev;
        keyboard_event.type=0;
        SDL_UnlockMutex(keyboard_event_s);

        break;
    //ADD CASES
    }



}
}










