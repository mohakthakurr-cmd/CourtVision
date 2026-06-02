#include <iostream>
#include <vector>

#include "Player.h"
#include "Analytics.h"
#include "DataManager.h"

using namespace std;

int main()
{
    Analytics analytics;
    vector<Player> players;
    DataManager::loadPlayers(players);

  int choice;

do
{
cout << R"(

 ██████╗ ██████╗ ██╗   ██╗██████╗ ████████╗██╗   ██╗██╗███████╗██╗ ██████╗ ███╗   ██╗
██╔════╝██╔═══██╗██║   ██║██╔══██╗╚══██╔══╝██║   ██║██║██╔════╝██║██╔═══██╗████╗  ██║
██║     ██║   ██║██║   ██║██████╔╝   ██║   ██║   ██║██║███████╗██║██║   ██║██╔██╗ ██║
██║     ██║   ██║██║   ██║██╔══██╗   ██║   ╚██╗ ██╔╝██║╚════██║██║██║   ██║██║╚██╗██║
╚██████╗╚██████╔╝╚██████╔╝██║  ██║   ██║    ╚████╔╝ ██║███████║██║╚██████╔╝██║ ╚████║
 ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝   ╚═╝     ╚═══╝  ╚═╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝

                          🏀 COURTVISION AI 🏀
                Basketball Analytics & Scouting Platform

==========================================================
🏀 Player Analytics
🏆 MVP Prediction Engine
📈 League Statistics Dashboard
🔍 Advanced Scouting Reports
⭐ Efficiency-Based Rankings
==========================================================

)";

cout << "\n=========== MAIN MENU ===========\n";
cout << "1. ➕ Add Player\n";
cout << "2. 👀 View Players\n";
cout << "3. 🏆 Leaderboard\n";
cout << "4. 💾 Save Data\n";
cout << "5. 🔍 Search Player\n";
cout << "6. 📋 Scouting Report\n";
cout << "7. ⭐ MVP Prediction\n";
cout << "8. 📈 League Statistics\n";
cout << "9. 🚪 Exit\n";
cout << "=================================\n";

        cout << "\nChoice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                Player p;
                p.inputPlayer();
                players.push_back(p);
                break;
            }

            case 2:
            {
                for(auto &p : players)
                    p.displayPlayer();
                break;
            }

            case 3:
                analytics.showLeaderboard(players);
                break;

            case 4:
                DataManager::savePlayers(players);
                break;

            case 5:
                analytics.searchPlayer(players);
                break;

            case 6:
                analytics.scoutingReport(players);
                break;

            case 7:
                analytics.predictMVP(players);
                break;

            case 8:
                analytics.leagueStats(players);
                break;

            case 9:
                DataManager::savePlayers(players);
                cout << "\nData Saved. Exiting...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 9);

    return 0;
}