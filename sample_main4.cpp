#include "std_lib_facilities_4.h"
#include "find_solution.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"
#include "HighScore.h"

vector<Ellipse*> Pancake_Maker(int level) {
	vector<Ellipse*> pancakes;
	vector<int> integers;
	for (int i = 0; i < level; i++) {
		integers.push_back(100-7*i);	
	}
	random_shuffle(integers.begin(),integers.end());
	for (int j = 0; j < level; j++) {
		Ellipse* temp = new Ellipse(Point(300, 300-20*j), integers[j], 20);
		pancakes.push_back(temp);
	}
	return pancakes;
}
// A function to flip the pancakes, with the integer given being the number of pancakes to flip
void flip(vector<Ellipse*> &pancakes, int num)
{
    int top = 0;
    int bottom = num-1;
    while(top<bottom)
        swap(pancakes[top],pancakes[bottom]);
}

//A function to use find solution to determine the number of flips required to solve the stack of pancakes
//int get_min_flips(const vector<int> integers)
//{
//    return find_solution(integers)->size();
//}

//Calculates a score based on the difficulty of the game, the number of flips used, and the minimum flips needed to solve it at the start of the game
int calculate_score(int difficulty, int numFlips, int minFlips)
{
    return (100-10*(numFlips-minFlips))*difficulty;
}
void display_high_scores(Simple_window &win1)
{
    HighScore scores = HighScore();
    stringstream column_header;
    Text title(Point(30,30),"High Scores");
    column_header << "Name" << setw(20) << "Score";
    win1.attach(title);
    if(scores.get_high_scores().size() > 0)
    {
        vector<Score> score_vector = scores.get_high_scores();
        Text header(Point(30,60),column_header.str());
        win1.attach(header);
        vector<Text*> text_scores;
	Text* t = new Text(Point(30,30), "hi!");
	stringstream s;
        for(int i = 0; i< score_vector.size(); ++i)
        {
            s << score_vector[i].get_name() << setw(20) << score_vector[i].get_score();
		text_scores.push_back(t);
            win1.attach(*(text_scores[i]));
        }
        win1.wait_for_button();
        win1.detach(header);
        for(int i = 0; i< text_scores.size(); ++i)
            win1.detach(*(text_scores[i]));
    }
    else
    {
        Text no_score(Point(30,60),"No Scores Yet");
        win1.attach(no_score);
        win1.wait_for_button();
        win1.detach(no_score);
        win1.detach(title);
    }
    
}
int main()
try {
  Simple_window win1(Point(100,200),600,400, "pancake");
	//Vector_ref<Ellipse> pancakes = Pancake_Maker(9);
	Image Splash_image(Point(0,0), "basic-pancake-recipe.jpg", Suffix::jpg);
	Text Splash_text(Point(100,300), "Obligatory splash screen to appeal to the grading rubrik nazis");
	win1.attach(Splash_image);
	win1.attach(Splash_text);
	win1.wait_for_button();
	win1.detach(Splash_text);
	win1.detach(Splash_image);
	Text Rules(Point(50,200), "Rules are for nerds");
	win1.attach(Rules);
	win1.wait_for_button();
	win1.detach(Rules);
        display_high_scores(win1);
	Text Level_Chooser(Point(200,200), "Choose from <insert buttons> to know how many pancakes");
	win1.attach(Level_Chooser);
	win1.wait_for_button();
	win1.detach(Level_Chooser);
	int level =1;
	cout << "type your level between 1 and 9" << endl;
	cin >> level;
	vector<Ellipse*> pancakes = Pancake_Maker(level);
	for(int i=0; i < level; i++) {
        	pancakes[i]->set_fill_color(94);
		win1.attach(*(pancakes[i]));
  	}
	win1.wait_for_button();
        flip(pancakes,3);
	for (int i = 0; i < level; i++) 
        {
		win1.detach(*(pancakes[i]));
	}
	for (int i = 0; i < pancakes.size(); ++i)
	{
		delete pancakes[i];
	}
	return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
