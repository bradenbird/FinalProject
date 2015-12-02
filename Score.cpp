#include "std_lib_facilities_4.h"
#include "Score.h"

Score::Score(String s, int n)
{
    name = s;
    score = n;
}

string Score::get_name()
{
    return name;
}

int Score::get_score()
{
    return score;
}

bool Score::operator>(Score s)
{
    return score > s.score;
}

bool Score::operator<(Score s)
{
    return score < s.score;
}

bool Score::operator==(Score s)
{
    return score == s.score;
}