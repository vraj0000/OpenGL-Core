#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
class Texture
{
    private:

    unsigned int m_Tex_ID;
    int m_TexWidth, m_TexHeight, m_TexNrChannels;
    std::string FilePath;

    public:
    
    void CreatBind (const std::string& TexPath);

    void Use(unsigned int slot) const;
    void Gen (const std::string& TexPath);
    void Bind(unsigned int slot = 0);

};

#endif