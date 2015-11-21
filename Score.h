/* 
 * File:   Score.h
 * Author: Braden
 *
 * Created on November 9, 2015, 6:02 PM
 */

#ifndef SCORE_H
#define	SCORE_H
#include "std_lib_facilities_4.h"
class Score
{
    string name;
    int score;
public:
    Score(string s, int n);
    string getName();
    int getScore();
    bool operator>(Score s);
    bool operator<(Score s);
    bool operator==(Score s);
};

#endif	/* SCORE_H */

