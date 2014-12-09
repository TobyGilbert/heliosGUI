#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <OpenGL/gl3.h>
#include <cmath>

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera{
public:
   Camera(glm::vec3 _pos);
   ~Camera();
   void setPosition(glm::vec3 _position);
   glm::mat4 getViewMatrix();

private:
   glm::vec3 m_position;
   glm::vec3 m_forward;
   glm::vec3 m_up;
};

#endif // CAMERA_H
