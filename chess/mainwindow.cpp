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
                QString fieldName = "Field_" + QString::number(i) + QString::number(j);

                QPushButton *btn = MainWindow::findChild<QPushButton *>(fieldName);
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

    pair<int,int> position = getPosition(field->objectName().toStdString());
    Color c = game.getCurrentMove();

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

pair<int,int> MainWindow::getPosition(string s) {
    string index = s.substr(s.length() - 2);
    int x = (int)index.at(0);
    int y = (int)index.at(1);
}
