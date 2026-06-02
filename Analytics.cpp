#include "Analytics.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Analytics::searchPlayer(vector<Player>& players)
{
    string name;

    cout << "Enter Player Name: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;

    for(auto &player : players)
    {
        if(player.name == name)
        {
            player.displayPlayer();
            found = true;
            break;
        }
    }

    if(!found)
        cout << "Player not found.\n";
}

void Analytics::scoutingReport(vector<Player>& players)
{
    string name;

    cout << "Enter Player Name: ";
    cin.ignore();
    getline(cin,name);

    for(auto &p : players)
    {
        if(p.name == name)
        {
            cout << "\n====================\n";
            cout << "SCOUTING REPORT\n";
            cout << "====================\n";

            cout << "Name: " << p.name << endl;
            cout << "Position: " << p.position << endl;

            cout << "\nStrengths:\n";

            if(p.points > 20)
                cout << "✓ Elite Scoring\n";

            if(p.rebounds > 8)
                cout << "✓ Strong Rebounding\n";

            if(p.assists > 5)
                cout << "✓ Excellent Playmaking\n";

            cout << "\nDraft Potential: ";

            if(p.points >= 25)
                cout << "Lottery Pick\n";
            else if(p.points >= 15)
                cout << "First Round\n";
            else
                cout << "Development Prospect\n";

            return;
        }
    }

    cout << "Player not found.\n";
}

void Analytics::predictMVP(vector<Player>& players)
{
    if(players.empty())
    {
        cout << "No players available.\n";
        return;
    }

    double bestScore = -1;
    Player mvp = players[0];

    for(auto &p : players)
    {
        double score =
            p.points * 0.5 +
            p.rebounds * 0.2 +
            p.assists * 0.3;

        if(score > bestScore)
        {
            bestScore = score;
            mvp = p;
        }
    }

    cout << "\n===== MVP PREDICTION =====\n";
    cout << "Predicted MVP: " << mvp.name << endl;
    cout << "MVP Score: " << bestScore << endl;
}

void Analytics::leagueStats(vector<Player>& players)
{
    if(players.empty())
    {
        cout << "No players available.\n";
        return;
    }

    double totalPts = 0;
    double totalReb = 0;
    double totalAst = 0;

    for(auto &p : players)
    {
        totalPts += p.points;
        totalReb += p.rebounds;
        totalAst += p.assists;
    }

    int n = players.size();

    cout << "\n===== LEAGUE STATISTICS =====\n";
    cout << "Average Points: " << totalPts / n << endl;
    cout << "Average Rebounds: " << totalReb / n << endl;
    cout << "Average Assists: " << totalAst / n << endl;
}

void Analytics::showLeaderboard(vector<Player>& players)
{
    sort(players.begin(), players.end(),
         [](Player a, Player b)
         {
             return a.calculateEfficiency() >
                    b.calculateEfficiency();
         });

    cout << "\n===== LEADERBOARD =====\n";

    for(int i = 0; i < players.size(); i++)
    {
        cout << i + 1
             << ". "
             << players[i].name
             << " | Efficiency: "
             << players[i].calculateEfficiency()
             << endl;
    }
}