#include "std_lib_facilities_4.h"
#include "find_solution.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"
#include "HighScore.h"
#include "new.h"
#include "Buttons.h"
Pancake gudpancakes;

void flip(vector<Ellipse*> &pancakes, int num)
{
    int top = 0;
    int bottom = num-1;
    cout << "start flipping\n";
    while(top<bottom)
    {
	pancakes[top]->move(0,pancakes[bottom]->point(0).y - pancakes[top]->point(0).y);
	pancakes[bottom]->move(0,pancakes[top]->point(0).y-pancakes[top]->point(0).y);
        swap(pancakes[top],pancakes[bottom]);
	cout << "blah";
	++top;
	--bottom;
    }
    Fl::redraw();
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
/*
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
	Text* t;// = new Text(Point(30,30), "hi!");
	stringstream s;
	cout << "Score Size: " << score_vector.size() <<  "\n";
        for(int i = 0; i< score_vector.size(); ++i)
        {
	    s.str(string());
	    s.clear();
            s << score_vector[i].get_name() << "                 " << score_vector[i].get_score();
	    t = new Text(Point(30, 90 + i*30),s.str());
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
*/
int main()
try {
			
  	Simple_window win1(Point(100,200),600,400, "pancake");
	win1.show();
	Image Splash_image(Point(0,0), "basic-pancake-recipe.jpg", Suffix::jpg);
	Text Splash_text(Point(100,300), "Obligatory splash screen to appeal to the grading rubrik nazis");
	win1.attach(Splash_image);
	pancake_window2 win3(Point(150,150),500,400,"play");
	win3.Level_button_maker(win3);
	win1.attach(Splash_text);
	Fl::run();
	win1.detach(Splash_text);
	win1.detach(Splash_image);
	//Text Rules(Point(50,200), "Rules are for nerds make sure to cp for reasons on the last slide");
	//win1.attach(Rules);
	//win1.wait_for_button();
	//win1.detach(Rules);
        //display_high_scores(win1);
	//Text Level_Chooser(Point(200,200), "Choose from <insert buttons> to know how many pancakes");
	//win1.attach(Level_Chooser);
	//win1.wait_for_button();
	//win1.detach(Level_Chooser);
	pancake_window2 win2{Point{150,150},600,400,"Play"};	
	int level = win3.button_pressed;
	while (level != 0) {
		cout << "type your level between 1 and 9" << endl;
		win2.show();
		//win2.wait_for_button();
		level= win3.button_pressed;
		//cout << "I waited\n";
		vector<Ellipse*> pancakes = gudpancakes.Pancake_Maker(level);
		win2.Flip_button_maker(win2, level);
		for(int i=0; i < level; i++){
        		pancakes[i]->set_fill_color(94);
			win2.attach(*(pancakes[i]));
  		}
		win2.redraw();
		cout << win2.button_pressed << endl;
		cout << "I attached pancakes\n";
		//while(true)
		//{
			Fl::flush();
			cout << pancakes[7] << endl;
			cout << "Start flip\n";
			flip(pancakes,win2.button_pressed);
			cout << pancakes[7] << endl;
			cout << "finished flip";
			//win2.show();
			cout << "no draw lines \n";
			for(auto p:pancakes)
				p->draw_lines();
			cout << "draw lines\n";
			Fl::flush();
		//}
		
		//win2.wait_for_button();	
		//for (int i = 0; i < level; i++) {
		//	win2.detach(*(pancakes[i]));
		//}
	cout << "type your level between 1 and 9" << endl;
	cin >> level;
	//vector<Ellipse*> pancakes = Pancake::Pancake_Maker(level);
	for(int i=0; i < level; i++) {
        	pancakes[i]->set_fill_color(94);
		//win1.detach(Rules);
		win2.attach(*(pancakes[i]));
  	}
	//win1.wait_for_button();
        flip(pancakes,3);
	for (int i = 0; i < level; i++) 
        {
		win2.detach(*(pancakes[i]));
	}
	//for (int i = 0; i < pancakes.size(); ++i)
	//{
	//	delete pancakes[i];
	//}
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
