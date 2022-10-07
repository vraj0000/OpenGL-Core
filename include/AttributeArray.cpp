#include "../Include/AttributeArray.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

AttributeArray::AttributeArray()
{
    glGenVertexArrays(1, &m_VAOID);
    glBindVertexArray(m_VAOID);
}

void AttributeArray::Bind() const
{
    glBindVertexArray(m_VAOID);
}
void AttributeArray::UnBind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}