#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <Qpainter>


#include "mgraph.h"
#include "pointer.h"
#include "dijkstra.h"


using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_go_pushButton_clicked();

private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent *);

public:
    vector<string> s_result;
    vector<Pointer> points_init;




};

#endif // MAINWINDOW_H
