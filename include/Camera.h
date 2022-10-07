#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include "../Include/glm/glm.hpp"
#include "../Include/glm/gtc/matrix_transform.hpp"

#include <vector>

class Camera
{
private:
    enum Camera_Movement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };
    

public:

    // camera Attributes
    glm::vec3 m_Position;
    glm::vec3 m_Front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_Up;
    glm::vec3 m_Right;
    glm::vec3 m_WorldUp;
    // euler Angles
    float m_Yaw                 = -90.0f;
    float m_Pitch               =  0.0f;
    
    float m_MovementSpeed       =  2.5f;
    float m_MouseSensitivity    =  0.1f;
    float m_Zoom                =  45.0f;                  

    // void CreateCamera(glm::vec3 position, glm::vec3 up , float yaw, float pitch);
    // // constructor with scalar values
    // void CreateCamera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
    glm::mat4 GetViewMatrix();

    // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);

    // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch);

    // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void ProcessMouseScroll(float yoffset);

private:
    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors();

};

#endif