#include "OpenGLWidget.h"
//------------------------------------------------------------------------------------------------------------------------
#include <QGuiApplication>
#include <iostream>
//------------------------------------------------------------------------------------------------------------------------
OpenGLWidget::OpenGLWidget(const QGLFormat _format, QWidget *_parent) : QGLWidget(_format,_parent){
    // set this widget to have the initial keyboard focus
    setFocus();
    // re-size the widget to that of the parent (in this case the GLFrame passed in on construction)
    this->resize(_parent->size());
}
//----------------------------------------------------------------------------------------------------------------------
OpenGLWidget::~OpenGLWidget(){
    delete m_cam;
}
//----------------------------------------------------------------------------------------------------------------------
void OpenGLWidget::initializeGL(){

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Initialize the camera
    m_cam = new Camera(glm::vec3(0.0, 1.0, 7.0));

    // as re-size is not explicitly called we need to do this.
    glViewport(0,0,width(),height());
}
//----------------------------------------------------------------------------------------------------------------------
void OpenGLWidget::resizeGL(const int _w, const int _h){
    // set the viewport for openGL
    glViewport(0,0,_w,_h);
    // TO DO: set the camera size values as the screen size has changed
}
//----------------------------------------------------------------------------------------------------------------------
void OpenGLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
//----------------------------------------------------------------------------------------------------------------------

