#ifndef BASICSCENE_H
#define BASICSCENE_H

#include "openglwidget.h"

class basicScene : public OpenGLWidget
{
    Q_OBJECT //must include to gain access to qt stuff
public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Our default constructor that calls the parent class openGLWigets constructor aswell
    /// @param _format - the openGL format used for the Qt context
    /// @param _parent - the parent widget the scene is used in
    //----------------------------------------------------------------------------------------------------------------------
    explicit basicScene(const QGLFormat _format, QWidget *_parent=0);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief default ctor
    //----------------------------------------------------------------------------------------------------------------------
    ~basicScene();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the initialize class is called once when the window is created and we have a valid GL context
    /// use this to setup any default GL stuff
    /// @warning you must first call the parent function openGLWiget::initializeGL() for this to work
    //----------------------------------------------------------------------------------------------------------------------
    void initializeGL();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this is called everytime we want to draw the scene
    /// @warning you must first call the parent function openGLWiget::paintGL() for this to work
    //----------------------------------------------------------------------------------------------------------------------
    void paintGL();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief called everytime the window resize
    /// @warning you must first call the parent function openGLWiget::resizeGL() for this to work
    //----------------------------------------------------------------------------------------------------------------------
    void resizeGL(const int _w, const int _h);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief a timer to update our scene
    //----------------------------------------------------------------------------------------------------------------------
    void timerEvent(QTimerEvent *);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief a simple function to load our tranform stack to our shader
    //----------------------------------------------------------------------------------------------------------------------
    void loadMatriciesToShader();
    //----------------------------------------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------

};

#endif // BASICSCENE_H
