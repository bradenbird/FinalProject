#include "HighScore.h"
#include "std_lib_facilities_4.h"

HighScore::HighScore()
{
    fstream file;
    string new_name;
    int new_score;
    file.open("scores.txt");
    while(!file.eof())
    {
        file >> new_name;
        file >> new_score;
        scores.push_back(Score(new_name, new_score));
    }
    file.close();
}

vector<Score> HighScore::getHighScores()
{
    return scores;
}

void HighScore::addNewScore(Score s)
{
    int index = 0;
    while(index<scores.size())
    {
        if(scores[index]>s)
            index++;
        else if(scores[index] == s)
            index++;
        else
        {
            Score temp = s;
            s = scores[index];
            scores[index] = temp;
            index++;
        } 
    }
    ofstream file;
    cout << remove("scores.txt");
    scores.pop_back();
    file.open("scores.txt");
    for(auto s: scores)
    {
        file << s.getName() << ' ' << s.getScore() << '\n';
    }
}