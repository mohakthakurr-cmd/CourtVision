#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <vector>
#include "Player.h"

class DataManager
{
public:
    static void savePlayers(std::vector<Player>& players);
    static void loadPlayers(std::vector<Player>& players);
};

#endif