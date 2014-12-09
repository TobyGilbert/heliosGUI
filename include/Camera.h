#ifndef CAMERA_H
#define CAMERA_H
//------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <OpenGL/gl3.h>
#include <cmath>
//------------------------------------------------------------------------------------------------------------------------
#define GLM_FORCE_RADIANS
//------------------------------------------------------------------------------------------------------------------------
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//------------------------------------------------------------------------------------------------------------------------
class Camera{
   //------------------------------------------------------------------------------------------------------------------------
public:
   //------------------------------------------------------------------------------------------------------------------------
   /// @brief Ctor
   //------------------------------------------------------------------------------------------------------------------------
   Camera(glm::vec3 _pos);
   //------------------------------------------------------------------------------------------------------------------------
   /// @brief Dtor
   //------------------------------------------------------------------------------------------------------------------------
   ~Camera();
   //------------------------------------------------------------------------------------------------------------------------
   /// @brief Sets the positions of the camera
   //------------------------------------------------------------------------------------------------------------------------
   void setPosition(glm::vec3 _position);
   //------------------------------------------------------------------------------------------------------------------------
   /// @brief Returns the view matrix
   //------------------------------------------------------------------------------------------------------------------------
   glm::mat4 getViewMatrix();
   //------------------------------------------------------------------------------------------------------------------------
private:
   //------------------------------------------------------------------------------------------------------------------------
   /// @brief The position of our camera
   //------------------------------------------------------------------------------------------------------------------------
   glm::vec3 m_position;
   //------------------------------------------------------------------------------------------------------------------------
   /// @brief The forward direction of our camera
   //------------------------------------------------------------------------------------------------------------------------
   glm::vec3 m_forward;
   //------------------------------------------------------------------------------------------------------------------------
   /// @brief The up direction of our camera
   //------------------------------------------------------------------------------------------------------------------------
   glm::vec3 m_up;
   //------------------------------------------------------------------------------------------------------------------------
};
//------------------------------------------------------------------------------------------------------------------------
#endif // CAMERA_H
//------------------------------------------------------------------------------------------------------------------------
