#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
public:
    string name;
    string position;

    double points;
    double rebounds;
    double assists;
    double steals;
    double blocks;

    double fgPercent;
    double threePercent;

    Player();

    void inputPlayer();
    void displayPlayer();

    double calculateEfficiency();
};

#endif