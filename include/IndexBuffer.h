#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H
class IndexBuffer
{
    private:

    unsigned int m_IBOID = 0;
    unsigned int m_Count;

    public:
    
    ~IndexBuffer();

    void CreatBind(const unsigned int* data, unsigned int count);
    void Bind() const;
    void UnBind() const;

    inline unsigned int GetCount() const {return m_Count;}
};

#endif