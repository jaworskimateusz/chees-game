#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QProcess>
#include "game.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    setWindowTitle("Chess");
    ui->setupUi(this);
    game = new Game();
    setCurrentMoveLayout();
    for(int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; j ++) {
            QPushButton *btn = getClickedButton(i, j);
            btn->setIcon(QIcon(""));
            btn->setIcon(QIcon(QString::fromStdString(game->getField(i,j)->getIconName())));
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
    if(game->getCurrentMove() == game->getField(position.first, position.second)->getPiece()->getColor() || isClicked) {
        if(!isClicked) {
            possiblePositions = game->getField(position.first, position.second)->getMoves(position.first, position.second);
            qDebug()<<possiblePositions;
            uncheckColors();
            field->setStyleSheet("QPushButton { background-color : #FFDEAD; }");
            colorPossibleMoves(possiblePositions);
            positionFrom = position;
            isClicked = true;
        } else {
            positionTo = position;
            if(isEmpty(positionTo) && hasMove()) {
                printFields();
                game->swapPiece(positionFrom, positionTo);
                printFields();
                updateGame();
            } else if (isOpponent(positionTo) && hasMove()) {
                printFields();
                game->swapPiece(positionFrom, positionTo);
                printFields();
                updateGame();
            }
            isClicked = false;
            uncheckColors();
        }
    }

}

void MainWindow::printFields() {
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            qDebug()<<QString::fromStdString(game->getField(i,j)->getIconName());
}

bool MainWindow::isEmpty(pair<int,int> positionTo) {
    if(game->getField(positionTo.first, positionTo.second)->getPieceType() == EMPTY_FIELD)
        return true;
    return false;
}

bool MainWindow::hasMove() {
    if(std::find(possiblePositions.begin(), possiblePositions.end(), positionTo) != possiblePositions.end())
       return true;
    return false;
}

bool MainWindow::isOpponent(pair<int,int> positionTo) {
    Color c = game->getField(positionTo.first, positionTo.second)->getPiece()->getColor();
    if(c != game->getCurrentMove() && c != INVISIBLE)
        return true;
    return false;
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
    for (auto & i : moves) {
        if(isEmpty(i))
            getClickedButton(i.first, i.second)->setStyleSheet("QPushButton {background-color: #FAEBD7;}");
        if(isOpponent(i))
            getClickedButton(i.first, i.second)->setStyleSheet("QPushButton {background-color: #800000;}");
    }

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

void MainWindow::updateGame() {
    for(int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; j ++) {
            QPushButton *btn = getClickedButton(i, j);
            btn->setIcon(QIcon(QString::fromStdString(game->getField(i,j)->getIconName())));
        }
    }
    setCurrentMoveLayout();
}

void MainWindow::setCurrentMoveLayout() {
    QToolButton *turn = MainWindow::findChild<QToolButton *>("Turn");
    game->setCurrentMove();
    if(game->getCurrentMove() == BLACK)
        turn->setIcon(QIcon(QString::fromStdString(":/img/left_arrow_black.png")));
    else
        turn->setIcon(QIcon(QString::fromStdString(":/img/right_arrow_white.png" )));
}
