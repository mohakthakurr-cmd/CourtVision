#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <vector>
#include "Player.h"

using namespace std;

class Analytics
{
public:
    void showLeaderboard(vector<Player>& players);

    void searchPlayer(vector<Player>& players);

    void scoutingReport(vector<Player>& players);

    void predictMVP(vector<Player>& players);

    void leagueStats(vector<Player>& players);
};

#endif