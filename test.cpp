#include "OpenGL.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

#include "include/stb_image.h"

class Test : public Application
{
private:
    Camera m_Camera;
    Shader m_MyShader;
    VertexBuffer m_VBO;
    IndexBuffer m_EBO;
    glm::mat4 m_ModelMatrix;         
    glm::mat4 m_ViewMatrix;          
    glm::mat4 m_Projection;    


    Texture m_Texture1, m_Texture2;
    unsigned int m_VAO;
    unsigned int tex;
    unsigned int i=0;

public:
    Test();
    virtual void init();
    virtual void end();
    virtual void Render();
    virtual void ProcessInput();
    virtual ~Test();

};

Test::Test()
{
    std::cout << "Creating Test \n";
}
void Test::ProcessInput()
{
    if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_Window, true);
}

void Test::init()
{
    m_MyShader.GenShader("../res/shaders/test.vs", "../res/shaders/test.fs"); 

    float vertices[] = {
        // positions          // colors           // texture coords
         0.9f,  0.9f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.9f, -0.9f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.9f, -0.9f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.9f,  0.9f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    glGenVertexArrays(1, &m_VAO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(m_VAO);
    m_VBO.CreatBind(vertices, sizeof(vertices));
    m_EBO.CreatBind(indices,6);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    glGenTextures(1,&tex);

}

void Test::Render()
{   
    int m_TexNrChannels = 3;
    int m_TexWidth = 500;
    int m_TexHeight = 500;
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    unsigned char data[m_TexHeight*m_TexWidth*m_TexNrChannels];
    srand(i);
    for(int i = 0 ;i<m_TexHeight*m_TexWidth*m_TexNrChannels; i+=m_TexNrChannels)
    {
        data[i+0] = (int)(rand() % 255);
        data[i+1] = data[i+0];
        data[i+2] = data[i+0];
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_TexWidth, m_TexHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, &data);
    glGenerateMipmap(GL_TEXTURE_2D);
    // render
    // ------
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);

    // render container
    m_MyShader.use();
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    i++;
}

void Test::end()
{
    glDeleteVertexArrays(1, &m_VAO);
}

Test::~Test()
{
    std::cout << "Rmoving Test" << "\n";
}

Application* getApp()
{
    printf("Getting Test \n");
    return new Test();
}
