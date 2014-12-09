#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <openglwidget.h>
#include <QToolBar>
#include <QToolButton>
#include <QDockWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    OpenGLWidget *m_openGLWidget;
    QTabWidget *m_tabs;
    QWidget *m_test;
    QToolButton *m_lightButton;
    QToolButton *m_meshButton;
    QToolBar *m_toolBar;
    QDockWidget *m_lightDock;
    QDockWidget *m_meshDock;



};

#endif // MAINWINDOW_H
