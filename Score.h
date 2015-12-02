/* Braden Bird
 * CSCE 121-516
 * HighScore.h
 */

#ifndef SCORE_H
#define	SCORE_H
#include "std_lib_facilities_4.h"

//A class to represent a score to be used in a list of high scores, containing a name and numerical score
class Score
{
    string name;
    int score;
public:
    Score(string s, int n);
    string get_name();
    int get_score();
    bool operator>(Score s);
    bool operator<(Score s);
    bool operator==(Score s);
};

#endif	/* SCORE_H */

