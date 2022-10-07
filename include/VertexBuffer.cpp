#include "../Include/VertexBuffer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_VBOID);
}
void VertexBuffer::CreatBind(const void* data, unsigned int size)
{
    glGenBuffers(1, &m_VBOID);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBOID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_VBOID);
}
void VertexBuffer::UnBind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}