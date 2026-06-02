#include "DataManager.h"
#include <fstream>
#include <iostream>

using namespace std;

void DataManager::savePlayers(vector<Player>& players)
{
    ofstream file("players.txt");

    for (Player p : players)
    {
        file << p.name << endl;
        file << p.position << endl;
        file << p.points << endl;
        file << p.rebounds << endl;
        file << p.assists << endl;
        file << p.steals << endl;
        file << p.blocks << endl;
        file << p.fgPercent << endl;
        file << p.threePercent << endl;
    }

    file.close();

    cout << "\nData Saved Successfully!\n";
}

void DataManager::loadPlayers(vector<Player>& players)
{
    ifstream file("players.txt");

    if (!file)
        return;

    Player p;

    while (getline(file, p.name))
    {
        getline(file, p.position);

        file >> p.points;
        file >> p.rebounds;
        file >> p.assists;
        file >> p.steals;
        file >> p.blocks;
        file >> p.fgPercent;
        file >> p.threePercent;

        file.ignore();

        players.push_back(p);
    }

    file.close();
}