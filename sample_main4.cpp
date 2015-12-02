#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"
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

int main()
try {
  Simple_window win1(Point(100,200),600,400, "pancake");
	Image Splash_image(Point(0,0), "basic-pancake-recipe.jpg", Suffix::jpg);
	Text Splash_text(Point(100,300), "Obligatory splash screen to appeal to the grading rubrik nazis");
	win1.attach(Splash_image);
	win1.attach(Splash_text);
	win1.wait_for_button();
	win1.detach(Splash_text);
	win1.detach(Splash_image);
	Text Rules(Point(50,200), "Rules are for nerds make sure to cp for reasons on the last slide");
	win1.attach(Rules);
	win1.wait_for_button();
	win1.detach(Rules);
	Text Level_Chooser(Point(200,200), "Choose from <insert buttons> to know how many pancakes");
	win1.attach(Level_Chooser);
	win1.wait_for_button();
	win1.detach(Level_Chooser);
	int level =1;
	while (level != 0) {
		cout << "type your level between 1 and 9" << endl;
		cin >> level;
		vector<Ellipse*> pancakes = Pancake_Maker(level);
		for(int i=0; i < level; i++) {
        		pancakes[i]->set_fill_color(94);
			win1.attach(*(pancakes[i]));
  		}
		win1.wait_for_button();
		for (int i = 0; i < level; i++) {
			win1.detach(*(pancakes[i]));
		}
	
	for (int i = 0; i < pancakes.size(); ++i)
	{
		delete pancakes[i];
	}
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
