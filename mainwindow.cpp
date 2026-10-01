#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    posX = 50;
    posY = 50;
    step = 2;

    // сцена 800 на 600
    myScene = new QGraphicsScene(0, 0, 800, 600);
    ui->graphicsView->setScene(myScene);

    // дрон - красный круг 20x20
    drone = myScene->addEllipse(0, 0, 20, 20);
    drone->setBrush(Qt::red);
    drone->setPos(posX, posY);

    droneTimer = new QTimer(this);
    connect(droneTimer, SIGNAL(timeout()), this, SLOT(moveUAV()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    droneTimer->start(20);
}

void MainWindow::moveUAV()
{
    // движение по квадрату 50..250
    if (posY == 50 && posX < 250)
        posX += step;           // вправо
    else if (posX == 250 && posY < 250)
        posY += step;           // вниз
    else if (posY == 250 && posX > 50)
        posX -= step;           // влево
    else if (posX == 50 && posY > 50)
        posY -= step;           // вверх

    // цвет от высоты
    if (posY < 300)
        drone->setBrush(Qt::blue);
    else
        drone->setBrush(Qt::red);

    drone->setPos(posX, posY);

    QString text = "X: " + QString::number(posX) + "  Y: " + QString::number(posY);
    ui->labelStatus->setText(text);
}
