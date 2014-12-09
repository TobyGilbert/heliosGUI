#include "mainwindow.h"
#include "ui_mainwindow.h"
//------------------------------------------------------------------------------------------------------------------------
#include <QFileDialog>
#include <QtWidgets>
//------------------------------------------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    // Set the OpenGL format required by QGLWidget
    QGLFormat format;
    format.setVersion(4,1);
    format.setProfile(QGLFormat::CoreProfile);

    // Create the widget used for drawing and add it to the desired location on the gui
    m_openGLWidget = new OpenGLWidget(format,this);
    ui->gridLayout->addWidget(m_openGLWidget,0,1,2,2);

    // A toolbar used to hold the button associated with different elements in the scene e.g. lighting, mesh options
    m_toolBar = new QToolBar();
    m_toolBar->setOrientation(Qt::Vertical);
    ui->gridLayout->addWidget(m_toolBar, 0, 0, 2, 1);

    //--------------------------------------------------------------------------------------------------------------------
    // ------------------------------------------------Light functionality------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------
    QPixmap light("icons/light.png");
    QIcon lightBtnIcon(light);
    m_lightButton = new QToolButton();
    m_lightButton->setIcon(lightBtnIcon);
    m_lightButton->setToolTip("Light options");
    m_toolBar->addWidget(m_lightButton);
    m_toolBar->addSeparator();

    // Create the dock for the light options
    m_lightWidget = new QWidget();
    m_lightDockLayout = new QGridLayout();
    m_lightWidget->setLayout(m_lightDockLayout);
    m_lightDock = new QDockWidget("Light Attributes");

    // Creae a drop down menu for the ligth type
    m_typeLabel = new QLabel("Type:");
    m_lightType = new QComboBox();
    m_lightType->addItem("Ambient Light");
    m_lightType->addItem("Area Light");
    m_lightType->addItem("Directional Light");
    m_lightType->addItem("Point Light");
    m_lightType->addItem("Spot Light");

    // Create the colour picker
    m_colourPicker = new QColorDialog();
    m_colourPicker->setHidden(true);
    m_colourLabel = new QLabel("Colour:");
    m_lightColourBtn = new QPushButton("Colour");

    // Make a slider to set the light intensity
    m_intensityLabel = new QLabel("Intensity:");
    m_lightIntensity = new QSlider();
    m_lightIntensity->setOrientation(Qt::Horizontal);

    // Add widgets to the light dock
    m_lightDockLayout->addWidget(m_typeLabel, 0, 0, 2, 1);
    m_lightDockLayout->addWidget(m_lightType, 0, 1, 2, 2);
    m_lightDockLayout->addWidget(m_colourLabel, 2, 0, 2, 1);
    m_lightDockLayout->addWidget(m_lightColourBtn, 2, 1, 2, 2);
    m_lightDockLayout->addWidget(m_colourPicker);
    m_lightDockLayout->addWidget(m_intensityLabel, 4, 0, 2, 1);
    m_lightDockLayout->addWidget(m_lightIntensity, 4, 1, 2, 2);

    // Add a spacer on the bottom
    m_lightSpacer = new QSpacerItem(1, 1, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    m_lightDockLayout->addItem(m_lightSpacer, 5, 0, 2, 1);
    m_lightDock->setWidget(m_lightWidget);
    m_lightDock->setHidden(true);
    this->addDockWidget(Qt::RightDockWidgetArea, m_lightDock);

    //--------------------------------------------------------------------------------------------------------------------
    // ------------------------------------------------Mesh functionality------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------
    // Button to access the mesh specific parameters
    QPixmap mesh("icons/teapot.png");
    QIcon meshBtnIcon(mesh);
    m_meshButton = new QToolButton();
    m_meshButton->setIcon(meshBtnIcon);
    m_meshButton->setToolTip("Mesh options");
    m_toolBar->addWidget(m_meshButton);
    m_toolBar->addSeparator();

    m_meshWidget = new QWidget();
    m_meshDockLayout = new QGridLayout();
    m_meshWidget->setLayout(m_meshDockLayout);
    m_meshDock = new QDockWidget("Mesh Attributes");

    m_translateLabel = new QLabel("Translate: ");
    m_meshDockLayout->addWidget(m_translateLabel, 0, 0, 1, 1);
    m_tranX = new QDoubleSpinBox();
    m_meshDockLayout->addWidget(m_tranX, 0, 1, 1, 1);
    m_tranY = new QDoubleSpinBox();
    m_meshDockLayout->addWidget(m_tranY, 0, 2, 1, 1);
    m_tranZ = new QDoubleSpinBox();
    m_meshDockLayout->addWidget(m_tranZ, 0, 3, 1, 1);
    m_rotateLabel = new QLabel("Rotate:");
    m_meshDockLayout->addWidget(m_rotateLabel, 1, 0, 1, 1);
    m_rotX = new QDoubleSpinBox();
    m_meshDockLayout->addWidget(m_rotX, 1, 1, 1, 1);
    m_rotY = new QDoubleSpinBox();
    m_meshDockLayout->addWidget(m_rotY, 1, 2, 1, 1);
    m_rotZ = new QDoubleSpinBox();
    m_meshDockLayout->addWidget(m_rotZ, 1, 3, 1, 1);

    m_meshSpacer = new QSpacerItem(1, 1, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    m_meshDockLayout->addItem(m_meshSpacer, 5, 0, 2, 1);
    m_meshDock->setWidget(m_meshWidget);
    m_meshDock->setHidden(true);
    this->addDockWidget(Qt::RightDockWidgetArea, m_meshDock);

    //--------------------------------------------------------------------------------------------------------------------
    // ------------------------------------------------Connections------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------
    // Link up the buttons so they do something when clicked
    connect(m_lightButton, SIGNAL(clicked(bool)), m_lightButton, SLOT(setChecked(bool)));
    connect(m_meshButton, SIGNAL(clicked(bool)), m_meshButton,  SLOT(setChecked(bool)));
    connect(m_lightButton, SIGNAL(clicked()), m_lightDock, SLOT(show()));
    connect(m_meshButton, SIGNAL(clicked()), m_meshDock, SLOT(show()));
    connect(m_lightColourBtn, SIGNAL(clicked()), m_colourPicker, SLOT(show()));
}
//------------------------------------------------------------------------------------------------------------------------
MainWindow::~MainWindow(){
    // Delete objects in the class
    delete ui;
    delete m_openGLWidget;
    delete m_lightButton;
    delete m_meshButton;
    delete m_toolBar;
    delete m_lightType;
    delete m_typeLabel;
    // Segmentation fault for some reason ????
    //delete m_lightSpacer;
    delete m_colourPicker;
    delete m_colourLabel;
    delete m_lightIntensity;
    delete m_intensityLabel;
    delete m_lightColourBtn;
    delete m_lightDockLayout;
    delete m_lightWidget;
    delete m_lightDock;
    delete m_tranX;
    delete m_tranY;
    delete m_tranZ;
    delete m_rotX;
    delete m_rotY;
    delete m_rotZ;
    delete m_translateLabel;
    //delete m_meshSpacer;
    delete m_rotateLabel;
    delete m_meshDockLayout;
    delete m_meshWidget;
    delete m_meshDock;
}
//------------------------------------------------------------------------------------------------------------------------
