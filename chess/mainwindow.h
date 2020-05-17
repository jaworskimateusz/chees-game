#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <game.h>
#include <algorithm>
#include "QPushButton"
#include "QMessageBox"

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 *  @file   mainwindow.h
 *  @brief  Main function for creating all logic, layout, moves
 *  @author Mateusz Jaworski
 *  @date   14-05-2020
 ***********************************************/
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    pair<int,int> positionFrom;
    pair<int,int> positionTo;
    bool isClicked = false;
    vector<pair<int,int>> possiblePositions;
private slots: 
    pair<int,int> getPosition(string s);
    bool isEmpty(pair<int,int> positionTo);
    bool hasMove();
    void onFieldClick();
    void onButtonClick();
    bool isOpponent(pair<int,int> positionTo);
    QPushButton * getClickedButton(int x, int y);
    void isGameOver();
    void uncheckColors();
    void colorPossibleMoves(vector<pair<int,int>> moves);
    void updateGame();
    void setCurrentMoveLayout();

};
#endif // MAINWINDOW_H
