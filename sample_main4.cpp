#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"

Vector_ref<Ellipse> Pancake_Maker(int level) {
	Vector_ref<Ellipse> pancakes;
	for (int i = 0; i < level; i++) {
		Ellipse* temp = new Ellipse(Point(300, 300-20*i), 100-3*i, 20);
		pancakes.push_back(temp);
	}
	return pancakes;
}

int main()
try {
  Simple_window win1(Point(100,200),600,400, "pankake");
	Vector_ref<Ellipse> pancakes = Pancake_Maker(8);
	Text Splash_text(Point(200,200), "James Dean faked his own death");
	win1.attach(Splash_text);
	win1.wait_for_button();
	win1.detach(Splash_text);
	Text Rules(Point(200,200), "Rules are for nerds");
	win1.attach(Rules);
	win1.wait_for_button();
	win1.detach(Rules);
	Text Level_Chooser(Point(200,200), "Choose from <insert buttons> to know how many pancakes");
	win1.attach(Level_Chooser);
	win1.wait_for_button();
	win1.detach(Level_Chooser);
	int level = 7;
	for(int i=0; i < level; i++) {
        	pancakes[i].set_fill_color(94);
		win1.attach(pancakes[i]);
  	}

	win1.wait_for_button();

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
