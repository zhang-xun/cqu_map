#include "mainwindow.h"
#include "ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //for floyd 算法
//    MGraph m;
//    m.Init();
//    m.Floyd();
//    m.PrintShortestDistance();

    //for dijkstra 算法
    //vector<int> s = init(0,11);


    //label 添加字体

    points_init.push_back(Pointer(0,0));         //0
    points_init.push_back(Pointer(510,310));     //1
    points_init.push_back(Pointer(610,280));     //2
    points_init.push_back(Pointer(610,200));     //3
    points_init.push_back(Pointer(480,180));     //4
    points_init.push_back(Pointer(320,280));     //5
    points_init.push_back(Pointer(210,270));     //6
    points_init.push_back(Pointer(340,170));     //7
    points_init.push_back(Pointer(70,260));      //8
    points_init.push_back(Pointer(200,160));     //9
    points_init.push_back(Pointer(140,100));     //10
    points_init.push_back(Pointer(70,60));       //11
    points_init.push_back(Pointer(250,80));      //12
    points_init.push_back(Pointer(320,90));      //13
    points_init.push_back(Pointer(500,80));      //14
    points_init.push_back(Pointer(610,100));     //15





    //添加图片
//   ui->widget->setAutoFillBackground(true);
//   QPalette palette;
//   QPixmap pixmap(":/image/Cqu_A_1.png");
//   palette.setBrush(QPalette::Window, QBrush(pixmap));
//   ui->widget->setPalette(palette);

//    ui->widget->show();

    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);



    //背景透明
    ui->p1_1->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_1->setPalette(pe);
    ui->p1_2->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_2->setPalette(pe);
    ui->p1_3->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_3->setPalette(pe);
    ui->p1_4->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_4->setPalette(pe);
    ui->p1_5->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_5->setPalette(pe);
    ui->p1_6->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_6->setPalette(pe);
    ui->p1_7->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_7->setPalette(pe);
    ui->p1_8->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_8->setPalette(pe);
    ui->p1_9->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_9->setPalette(pe);
    ui->p1_10->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_10->setPalette(pe);
    ui->p1_11->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_11->setPalette(pe);
    ui->p1_12->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_12->setPalette(pe);
    ui->p1_13->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_13->setPalette(pe);
    ui->p1_14->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_14->setPalette(pe);
    ui->p1_15->setAttribute(Qt::WA_TranslucentBackground);
    ui->p1_15->setPalette(pe);
//setAttribute(Qt::WA_TranslucentBackground)



}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_go_pushButton_clicked()
{
    //for dijkstra 算法
    int start,end;
    try{
         start = std::stoi(ui->from_lineedit->text().toStdString());
         end =  std::stoi(ui->to_lineedit->text().toStdString());
    }
    catch (exception error)
    {
        cout << "from and to point must start with numbers" << endl;
    }

     s_result = init(start,end) ;

    string text;
    for(auto i = 0; i <s_result.size(); i++)
    {

        text.append(s_result[i]);
        if (i != s_result.size()-1 )
        {
            text.append("-->");
        }
    }

    cout <<"text:" <<  text << endl;
    ui->textEdit->setText(QString::fromStdString(text));

    //paint on the widgets


    QPainter painter(ui->centralWidget);
    painter.setPen(QPen(Qt::blue,4));//设置画笔形式


    for(int i = 0; i< s_result.size()-1; i++)
    {
        //for(int  j = i+1; j < s.size(); ++)
        {
            int m = std::stoi(s_result[i]);
            int n = std::stoi(s_result[i+1]);
//            cout << "point:" ;
//            cout << j<<endl;
//            cout << points_init[j].getx() <<"\t"<< points_init[j].gety() << endl;

           // cout << points_init[m].getx() << points_init[m].gety()<< points_init[n].getx()<<points_init[n].gety()<<endl;
            painter.drawLine(points_init[m].getx(),points_init[m].gety(),
                             points_init[n].getx(),points_init[n].gety());//画直线
        }

    }






}








void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter2(ui->centralWidget);
    painter2.setPen(QPen(Qt::blue,4));//设置画笔形式
    painter2.drawLine(20,20,220,220);//画直线
    painter2.drawLine(20,220,220,20);
    painter2.drawEllipse(20,20,200,200);//画圆
    painter2.drawRect(20,20,200,200);//画矩形
}
