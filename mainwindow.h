#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void moveUAV();
    void on_btnStart_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *myScene;
    QGraphicsEllipseItem *drone;
    QTimer *droneTimer;

    int posX;
    int posY;
    int step;
};

#endif // MAINWINDOW_H
