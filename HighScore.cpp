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

vector<Score> HighScore::get_high_scores()
{
    return scores;
}

void HighScore::add_new_score(Score s)
{
    int index = 0;
    if(scores.size() == 0)
        scores.push_back(s);
    else
        while(index<scores.size())
        {
            if(scores[index]>s)
                index++;
            else if(scores[index] == s)
                index++;
            else
            {
                swap(scores[index],s);
                index++;
            } 
        }
    ofstream file;
    cout << remove("scores.txt");
    if(scores.size()!=0)
        scores.pop_back();
    file.open("scores.txt");
    for(auto s: scores)
    {
        file << s.get_name() << ' ' << s.get_score() << '\n';
    }
    file.close();
}
