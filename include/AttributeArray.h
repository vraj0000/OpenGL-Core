#ifndef AttributeArray_H
#define AttributeArray_H


class AttributeArray
{
    private:
    unsigned int m_VAOID;

    public:
    AttributeArray();

    void Bind() const;
    void UnBind() const;

};

#endif