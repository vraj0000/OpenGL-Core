#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "App.h"

void Application::init(){}
void Application::end(){}
void Application::Render(){}

void Application::ProcessInput(){}

Application::~Application()
{
    std::cout << "Rmoving Application" << "\n";
}

