#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    QGLFormat format;
    format.setVersion(4,1);
    format.setProfile(QGLFormat::CoreProfile);

    m_openGLWidget = new OpenGLWidget(format,this);
    ui->gridLayout->addWidget(m_openGLWidget,0,1,2,2);

    m_toolBar = new QToolBar();
    m_toolBar->setOrientation(Qt::Vertical);
    ui->gridLayout->addWidget(m_toolBar, 0, 0, 2, 1);

    // Light functionality
    QPixmap light("icons/light.png");
    QIcon lightBtnIcon(light);
    m_lightButton = new QToolButton();
    m_lightButton->setIcon(lightBtnIcon);
    m_toolBar->addWidget(m_lightButton);
    //m_lightButton->setCheckable(true);
    m_lightButton->setToolTip("Light options");

    // Create the dock for the light options
    m_lightDock = new QDockWidget("Light Attributes");
    m_lightDock->setHidden(true);
    this->addDockWidget(Qt::RightDockWidgetArea, m_lightDock);

    m_meshDock = new QDockWidget("Mesh Attributes");
    m_meshDock->setHidden(true);
    this->addDockWidget(Qt::RightDockWidgetArea, m_meshDock);

    // Button to access the mesh specific parameters
    QPixmap mesh("icons/teapot.png");
    QIcon meshBtnIcon(mesh);
    m_meshButton = new QToolButton();
    m_meshButton->setIcon(meshBtnIcon);
    m_meshButton->setToolTip("Mesh options");
    m_toolBar->addWidget(m_meshButton);

    connect(m_lightButton, SIGNAL(clicked(bool)), m_lightButton, SLOT(setChecked(bool)));
    connect(m_meshButton, SIGNAL(clicked(bool)), m_meshButton,  SLOT(setChecked(bool)));
    connect(m_lightButton, SIGNAL(clicked()), m_lightDock, SLOT(show()));
    connect(m_meshButton, SIGNAL(clicked()), m_meshDock, SLOT(show()));

}


MainWindow::~MainWindow(){
    delete ui;
    delete m_openGLWidget;
    delete m_lightButton;
    delete m_meshButton;
    delete m_toolBar;
    delete m_lightDock;
    delete m_meshDock;
}
