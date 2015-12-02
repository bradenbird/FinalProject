#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

class pancake_window2 : Graph_lib::Window {
public: pancake_window2 ( Point xy, int w, int h, const string& title );
	
	
private:
	//Widgets
	Button quit_button2; //quit button
	In_box initials; //initials in_box
	Button enter_button; //enters initials that's in in_box
	Button dir_button; //next window to play
	Button back_button; //back to directions
	
	Button two_button;
	Button three_button;
	Button four_button;
	Button five_button;
	Button six_button;
	Button seven_button;
	Button eight_button;
	Button nine_button;

	void enter();
	void quit2();
	void dir();

	void back();
	
	void two();
	void three();
	void four();
	void five();
	void six();
	void seven();
	void eight();
	void nine();
	
	//callback functions
	static void cb_quit2(Address, Address);
	static void cb_enter(Address, Address);
	static void cb_dir(Address, Address);

	static void cb_back(Address, Address);
	
	static void cb_two(Address, Address);
	static void cb_three(Address, Address);
	static void cb_four(Address, Address);
	static void cb_five(Address, Address);
	static void cb_six(Address, Address);
	static void cb_seven(Address, Address);
	static void cb_eight(Address, Address);
	static void cb_nine(Address, Address);
};


pancake_window2::pancake_window2(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
	quit_button2(Point(x_max()-70,y_max()-20), 70, 20, "&QUIT", cb_quit2), //quit button
	initials(Point(315,0),70,20,"Initials: "),
	enter_button(Point(415,0),70,20,"ENTER", cb_enter), //enters initials
	dir_button(Point(300,320),105,20,"HOW TO PLAY", cb_dir),//will eventually go to directions screen
	
	back_button(Point(0,y_max()-20),70,20, "BACK", cb_back),
	
	two_button(Point(40,250), 70, 20, "&2", cb_two),
	three_button(Point(100,250), 70, 20, "&3", cb_three),
	four_button(Point(140,250), 70, 20, "&4", cb_four),
	five_button(Point(200,250), 70, 20, "&5", cb_five),
	six_button(Point(240,250), 70, 20, "&6", cb_six),
	seven_button(Point(300,250), 70, 20, "&7", cb_seven),
	eight_button(Point(340,250), 70, 20, "&8", cb_eight),
	nine_button(Point(400,250), 70, 20, "&9", cb_nine)
	
{
	Graph_lib::Window::Fl_Window::color(24);// changes window color
	attach(quit_button2);
	attach(initials);
	attach(enter_button);
	attach(dir_button);

	attach(back_button);

	

	attach(two_button);
	attach(three_button);
	attach(four_button);
	attach(five_button);
	attach(six_button);
	attach(seven_button);
	attach(eight_button);
	attach(nine_button);

}
//------------------------------------------------------------------------------
void pancake_window2::cb_quit2(Address, Address pw)
{
	reference_to<pancake_window2>(pw).quit2();
} 
void pancake_window2::quit2()
{
   hide();        // curious FLTK idiom for delete window
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void pancake_window2::cb_enter(Address, Address pw)
{
	reference_to<pancake_window2>(pw).enter();
}
void pancake_window2::enter() 
{
	

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void pancake_window2::cb_dir(Address, Address pw)
{
	reference_to<pancake_window2>(pw).dir();
}
void pancake_window2::dir() 
{
	cout << "how to button works";
	bool button_pushed = true;
	hide();
	//directions window info
	gui_main();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void pancake_window2::cb_back(Address, Address pw)
{
	reference_to<pancake_window2>(pw).back();
}
void pancake_window2::back() 
{
	bool button_pushed = true;
	hide();
	
	gui_main();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



void pancake_window2::cb_two(Address, Address pw)
{
	reference_to<pancake_window2>(pw).two();
}
void pancake_window2::two() 
{
	bool button_pushed = true;
	
	hide();

	gui_main();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void pancake_window2::cb_three(Address, Address pw)
{
	reference_to<pancake_window2>(pw).three();
}
void pancake_window2::three() 
{
bool button_pushed = true;

hide();

gui_main();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void pancake_window2::cb_four(Address, Address pw)
{
	reference_to<pancake_window2>(pw).four();
}
void pancake_window2::four() 
{
	bool button_pushed = true;

	hide();

	gui_main();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void pancake_window2::cb_five(Address, Address pw)
{
	reference_to<pancake_window2>(pw).five();
}
void pancake_window2::five() 
{
	bool button_pushed = true;

hide();
	
	gui_main();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void pancake_window2::cb_six(Address, Address pw)
{
	reference_to<pancake_window2>(pw).six();
}
void pancake_window2::six() 
{
	bool button_pushed = true;

	hide();

gui_main();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void pancake_window2::cb_seven(Address, Address pw)
{
	reference_to<pancake_window2>(pw).seven();
}
void pancake_window2::seven() 
{
	bool button_pushed = true;
	
	hide();
	
	gui_main();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void pancake_window2::cb_eight(Address, Address pw)
{
	reference_to<pancake_window2>(pw).eight();
}
void pancake_window2::eight() 
{
	bool button_pushed = true;

	hide();

	gui_main();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void pancake_window2::cb_nine(Address, Address pw)
{
	reference_to<pancake_window2>(pw).nine();
}
void pancake_window2::nine() 
{
	bool button_pushed = true;
	
	hide();

gui_main();
}

int main()
try {
pancake_window2 win{Point{100,100},600,400,"Pancake"};
return gui_main();
}
catch(exception& e) {
cerr << "exception: " << e.what() << '\n';
return 1;
}
catch (...) {
cerr << "Some exception\n";


}
