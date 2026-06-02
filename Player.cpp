#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
    points = rebounds = assists = steals = blocks = 0;
    fgPercent = threePercent = 0;
}

void Player::inputPlayer()
{
    cin.ignore(1000, '\n');

    cout << "\nPlayer Name: ";
    getline(cin, name);

    cout << "Position: ";
    getline(cin, position);

    cout << "Points Per Game: ";
    cin >> points;

    cout << "Rebounds Per Game: ";
    cin >> rebounds;

    cout << "Assists Per Game: ";
    cin >> assists;

    cout << "Steals Per Game: ";
    cin >> steals;

    cout << "Blocks Per Game: ";
    cin >> blocks;

    cout << "FG %: ";
    cin >> fgPercent;

    cout << "3PT %: ";
    cin >> threePercent;

    cin.ignore(1000, '\n');
}

void Player::displayPlayer()
{
    cout << "\n=========================\n";

    cout << "Name: " << name << endl;
    cout << "Position: " << position << endl;

    cout << "PPG: " << points << endl;
    cout << "RPG: " << rebounds << endl;
    cout << "APG: " << assists << endl;
    cout << "SPG: " << steals << endl;
    cout << "BPG: " << blocks << endl;

    cout << "FG%: " << fgPercent << endl;
    cout << "3PT%: " << threePercent << endl;

    cout << "Efficiency: "
         << calculateEfficiency()
         << endl;
}

double Player::calculateEfficiency()
{
    return points +
           rebounds +
           assists +
           (steals * 2) +
           (blocks * 2);
}