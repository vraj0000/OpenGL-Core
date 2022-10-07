#include "../Include/IndexBuffer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void IndexBuffer::CreatBind(const unsigned int* data, unsigned int count)
{
    m_Count = count;
    glGenBuffers(1, &m_IBOID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBOID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}
IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_IBOID);
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBOID);
}
void IndexBuffer::UnBind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}