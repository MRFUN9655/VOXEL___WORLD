
                                 //ADD STATIC AND INLINE
                                 //visualize = trust(no talk,only action)
                                //\/\\/\/\///\\\\\\\\\////\
//                                   \\//        \\//
//                                   //\\        //\\
//                              ___________________________
//                              \                         /
//                              \    \   |   |   |    /   /
//                               \    \  |   |   |   /   /
//                                \                     /
//                                  manage time in screen illution



//importers//
#include"window.h"//windowing system wrapper
#include"gl.h"//gl shorten wrapers
#include"event.h"//event_updater
#include"world_updater.h"//slow , world updater
//global variables
bool e_runner=1;
bool runner=1;//runner
win_t window={};
SDL_Mutex *keyboard_event_s=NULL;
SDL_Mutex *xyrot_s=NULL;
//game mem
int fps=1;
int sen=10;
//gl mem
GLfloat x2,y2,rot_x2,rot_y2=0.0f;
GLuint vbo2;
float vertices2[27];
GLfloat x,y,rot_x,rot_y=0.0f;
GLuint vbo;

float vertices[27] = {
 -0.1f,-1.0f,0.0f,
  0.1f,-1.0f,0.0f,
  0.1f, -1.0f,0.0f,
 -0.1f, -1.0f,0.0f,
 -0.1f,-1.0f,0.0f,
  0.0f,-1.0f,-0.3f,
  0.1f, -1.0f,0.0f,
  0.1f,-1.0f,0.0f,
  0.0f,-1.0f,-0.3f
};//vertex buffer





//funcs//
//main
void main(){

//init
init();
printf("hi");
//ALLOC
//win sys mem
    window.window_hand=SDL_CreateWindow("hiii",1200,600,SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    FPS_MODE(window.window_hand);

//GL CONFIGS
    window.context=SDL_GL_CreateContext(window.window_hand);//WINDOW
    glViewport(0,0,1200,600);//pixel settings
    glEnable(GL_DEPTH_TEST);// enable 3D depth
    glClearColor(0.1f,0.7f,1.0f,1.0f);//background color
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    MatrixMode(GL_PROJECTION);
    gluPerspective(100.0, 1, 0.1, 100.0);//perspective
    //glDisableClientState(GL_VERTEx_ARRAY);
    keyboard_event_s=SDL_CreateMutex();
    xyrot_s=SDL_CreateMutex();
    SDL_Thread *event_updater=SDL_CreateThread(event,"event_updater",NULL);
    //SDL_Thread *world__updater=SDL_CreateThread(world_updater,"world updater",NULL);//name conflict (segmentation fault)
while(runner){
delay(fps/100);//loop slower
SDL_LockMutex(xyrot_s);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//clean
        MatrixMode(GL_MODELVIEW);
        glRotatef(y*1,1,0,0);
        glRotated(x,0,1,0);
        glTranslatef(rot_x,0,rot_y);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, 0);
        glDrawArrays(GL_LINE_LOOP, 0,9);
SDL_GL_SwapWindow(window.window_hand); // Show frame
SDL_UnlockMutex(xyrot_s);
//event cases

}
SDL_Quit();//exit
}





















