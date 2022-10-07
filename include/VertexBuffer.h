#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

class VertexBuffer
{
    private:

    unsigned int m_VBOID = 0;

    public:
       
    ~VertexBuffer();
    
    void CreatBind(const void* data, unsigned int size);
    void Bind() const;
    void UnBind() const;
};

#endif