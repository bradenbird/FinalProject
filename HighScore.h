/* Braden Bird
 * CSCE 121-516
 * HighScore.h
 */

#ifndef HIGHSCORE_H
#define	HIGHSCORE_H
#include "std_lib_facilities_4.h"
#include "Score.h"

//A class to manage viewing and updating of the high scores, through the usage of adding a new high score and returning the current high scores
class HighScore
{
    vector<Score> scores;
public:
    HighScore();
    vector<Score> get_high_scores();
    void add_new_score(Score s);
    
};

#endif	/* HIGHSCORE_H */

