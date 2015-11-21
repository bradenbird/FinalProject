/* Braden Bird
 * CSCE 121-516
 * HighScore.h
 */

#ifndef HIGHSCORE_H
#define	HIGHSCORE_H
#include "std_lib_facilities_4.h"
#include "Score.h"

class HighScore
{
    vector<Score> scores;
public:
    HighScore();
    vector<Score> getHighScores();
    void addNewScore(Score s);
    
};

#endif	/* HIGHSCORE_H */

