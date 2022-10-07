#ifndef SHADER_H
#define SHADER_H

#include <unordered_map>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"
class Shader
{
    protected:
    /**
     * My UnniformIdCache on CPU side for faster responce
     * due to not calling for unifrom id over and over again.
     */
    // ------------------------------------------------------------------------
    mutable std::unordered_map<std::string, GLint> m_UniformLocCache;


    public:
    unsigned int ID;
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    void GenShader(const char* vertexPath, const char* fragmentPath);

    // caching system for uniformID
    GLint getUniformLoc(const std::string& name) const;

    // activate the shader
    // ------------------------------------------------------------------------
    void use();

    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string &name, bool value) const;

    // ------------------------------------------------------------------------
    void setInt(const std::string &name, int value) const;
    // ------------------------------------------------------------------------
    void setFloat(const std::string &name, float value) const;

    void setMat4(const std::string &name, const glm::mat4 &mat) const;

    private:

    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(unsigned int shader, std::string type);
};
#endif