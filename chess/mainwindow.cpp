#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QProcess>
#include "game.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);
    this->game = Game();

        for(int i = 0; i < 8; i ++){
            for (int j = 0; j < 8; j ++) {
                QPushButton *btn = getClickedButton(i, j);
                btn->setIcon(QIcon(QString::fromStdString(game.fields[i][j].getIconName())));
                connect(btn,
                        SIGNAL(released()),
                        this,
                        SLOT(onFieldClick()));
            }

        }

        connect(MainWindow::findChild<QToolButton *>("NewGame"),
                SIGNAL(released()),
                this,
                SLOT(onButtonClick()));
        connect(MainWindow::findChild<QToolButton *>("Quit"),
                SIGNAL(released()),
                this,
                SLOT(onButtonClick()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onFieldClick() {
    QPushButton *field = (QPushButton *)sender();
    qDebug() << field->objectName();

    Color c = game.getCurrentMove();
    pair<int,int> position = getPosition(field->objectName().toStdString());
    vector<pair<int,int>> possiblePositions = game.getField(position.first, position.second).getMoves(position.first, position.second);

    qDebug()<<possiblePositions;
    uncheckColors();
    field->setStyleSheet("QPushButton { background-color : #FFDEAD; }");
    colorPossibleMoves(possiblePositions);

}

void MainWindow::uncheckColors() {
    for(int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; j ++) {
            QPushButton *btn = getClickedButton(i,j);
            if((i+j) % 2 == 0 )
                btn->setStyleSheet("QPushButton {background-color: #FFFFFF;}");
            else
                btn->setStyleSheet("QPushButton {background-color: #808080;}");
        }
    }
}

void MainWindow::colorPossibleMoves(vector<pair<int,int>> moves) {
    for (auto & i : moves)
        getClickedButton(i.first, i.second)->setStyleSheet("QPushButton {background-color: #FAEBD7;}");

}

void MainWindow::onButtonClick() {
    QToolButton *btn = (QToolButton *)sender();
    if(btn->objectName() =="NewGame") {
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
    if(btn->objectName() == "Quit")
        QApplication::quit();

}

QPushButton * MainWindow::getClickedButton(int x, int y) {
    QString fieldName = "Field_" + QString::number(x) + QString::number(y);
    QPushButton *btn = MainWindow::findChild<QPushButton *>(fieldName);
    return btn;
}

pair<int,int> MainWindow::getPosition(string s) {
    string index = s.substr(s.length() - 2);
    int x = stoi(index.substr(0,1));
    int y = stoi(index.substr(1,2));
    return pair<int,int>(x,y);
}
