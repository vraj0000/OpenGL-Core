#define STB_IMAGE_IMPLEMENTATION
#include "../Include/stb_image.h"
#include "../Include/Texture.h"


#include <iostream>
#include <cmath>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void Texture::CreatBind (const std::string& TexPath)

{
    m_TexNrChannels = 0;
    m_TexWidth = 0;
    m_TexHeight = 0;
    FilePath = TexPath;
    glGenTextures(1, &m_Tex_ID);
    glBindTexture(GL_TEXTURE_2D, m_Tex_ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char *data = stbi_load(TexPath.c_str(), &m_TexWidth, &m_TexHeight, &m_TexNrChannels, 0);
    if (m_TexNrChannels == 4)
    {
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_TexWidth, m_TexHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
    }
    else
    {
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_TexWidth, m_TexHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
    }
    stbi_image_free(data);
}

void Texture::Use(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_Tex_ID);
}

