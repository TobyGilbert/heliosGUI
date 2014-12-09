#include "Camera.h"

Camera::Camera(glm::vec3 _pos){
   m_position = _pos;
   m_forward = glm::vec3(0.0, 0.0, -1.0);
   m_up = glm::vec3(0.0, 1.0, 0.0);
}

Camera::~Camera(){
}

glm::mat4 Camera::getViewMatrix(){
   return glm::lookAt(m_position, glm::vec3(0.0, 0.0, 0.0), m_up);
}

void Camera::setPosition(glm::vec3 _position){
   m_position = _position;
}
