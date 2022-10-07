// #ifndef APP_H
// #define APP_H

#include <unordered_map>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Application
{
private:
    

public:

    GLFWwindow* m_Window;
    unsigned int m_Hight;
    unsigned int m_Weidth;
    // void CreatWindow();

    virtual void init();
    virtual void end();
    virtual void Render();

    virtual void ProcessInput();

    virtual ~Application();

};

Application* getApp();

// #endif
