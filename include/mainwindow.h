#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//------------------------------------------------------------------------------------------------------------------------
#include <QMainWindow>
#include <QToolBar>
#include <QToolButton>
#include <QDockWidget>
//------------------------------------------------------------------------------------------------------------------------
#include <OpenGLWidget.h>
//------------------------------------------------------------------------------------------------------------------------
namespace Ui {
    class MainWindow;
}
//------------------------------------------------------------------------------------------------------------------------
class MainWindow : public QMainWindow
{
    //------------------------------------------------------------------------------------------------------------------------
    Q_OBJECT
    //------------------------------------------------------------------------------------------------------------------------
public:
    //------------------------------------------------------------------------------------------------------------------------
    /// @brief Ctor
    //------------------------------------------------------------------------------------------------------------------------
    explicit MainWindow(QWidget *parent = 0);
    //------------------------------------------------------------------------------------------------------------------------
    /// @brief Dtor
    //------------------------------------------------------------------------------------------------------------------------
    ~MainWindow();
    //------------------------------------------------------------------------------------------------------------------------
private:
    //------------------------------------------------------------------------------------------------------------------------
    /// @brief Ui object which contains all gui objects
    //------------------------------------------------------------------------------------------------------------------------
    Ui::MainWindow *ui;
    //------------------------------------------------------------------------------------------------------------------------
    /// @brief Widget for drawing (Our openGL context)
    //------------------------------------------------------------------------------------------------------------------------
    OpenGLWidget *m_openGLWidget;
    //------------------------------------------------------------------------------------------------------------------------
    /// @brief A widget for the toolbar used to hold gui buttons
    //------------------------------------------------------------------------------------------------------------------------
    QToolBar *m_toolBar;
    //------------------------------------------------------------------------------------------------------------------------
    /// @brief A tool bar button to bring up the attributes assoiciated with the lights in the scene
    //------------------------------------------------------------------------------------------------------------------------
    QToolButton *m_lightButton;
    //------------------------------------------------------------------------------------------------------------------------
    /// @brief A tool bar button to bring up the attributes associatied with the meshes in the scene
    //------------------------------------------------------------------------------------------------------------------------
    QToolButton *m_meshButton;
    //------------------------------------------------------------------------------------------------------------------------
    /// @brief A pop out gui window used for holding light options
    //------------------------------------------------------------------------------------------------------------------------
    QDockWidget *m_lightDock;
    //------------------------------------------------------------------------------------------------------------------------
    /// @brief A pop out gui wondow used for holding mesh options
    //------------------------------------------------------------------------------------------------------------------------
    QDockWidget *m_meshDock;
    //------------------------------------------------------------------------------------------------------------------------
};
//------------------------------------------------------------------------------------------------------------------------
#endif // MAINWINDOW_H
//------------------------------------------------------------------------------------------------------------------------
