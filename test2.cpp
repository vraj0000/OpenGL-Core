#define STB_IMAGE_IMPLEMENTATION
#include "Include/stb_image.h"
#include <iostream>
int main()
{   

    int width, height, nrChannels;
    unsigned char *data = stbi_load("res/images/I.png", &width, &height, &nrChannels, 0);
    for(int i = 0 ;i<height*width*nrChannels; i+=nrChannels)
    {
       
        std::cout << (int)data[i+0] << " \n";
        std::cout << (int)data[i+1] << " \n";
        std::cout << (int)data[i+2] << " \n";
    }
    for(int i = 0 ;i<height*width*nrChannels; i+=nrChannels)
    {
       
        std::cout << (int)data[i+0] << " \n";
        std::cout << (int)data[i+1] << " \n";
        std::cout << (int)data[i+2] << " \n";
    }
    std::cout << nrChannels << " " << width << " " << height << " \n";
    return 0;
}