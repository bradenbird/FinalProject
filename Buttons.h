#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

class pancake_window2 : public Graph_lib::Window {
public: pancake_window2 ( Point xy, int w, int h, const string& title );
	//int wait_for_button();
	int button_pressed;
	string player_initials;
	vector<Text*> text;
	void Level_button_maker(Window& w);
	void Flip_button_maker(Window& w, int level);
	void display_high_scores();
	void detach_high_scores();
private:
	//Widgets
	//Button quit_button2; //quit button
	In_box initials; //initials in_box
	Button enter_button; //enters initials that's in in_box
	/*Button dir_button; //next window to play
	Button back_button; //back to directions
	
	Button two_button;
	Button three_button;
	Button four_button;
	Button five_button;
	Button six_button;
	Button seven_button;
	Button eight_button;
	Button nine_button;
	Button view_hs_button;
	*/
	void enter();
	void quit2();
	void dir();
	void back();
	
	void one();
	void two();
	void three();
	void four();
	void five();
	void six();
	void seven();
	void eight();
	void nine();
	void view_high_scores();
	
	//callback functions
	static void cb_quit2(Address, Address);
	static void cb_enter(Address, Address);
	static void cb_dir(Address, Address);

	static void cb_back(Address, Address);
	static void cb_one(Address, Address);
	static void cb_two(Address, Address);
	static void cb_three(Address, Address);
	static void cb_four(Address, Address);
	static void cb_five(Address, Address);
	static void cb_six(Address, Address);
	static void cb_seven(Address, Address);
	static void cb_eight(Address, Address);
	static void cb_nine(Address, Address);
	static void cb_view_high_scores(Address, Address);
};


pancake_window2::pancake_window2(Point xy, int w, int h, const string& title) 
    :Window(xy,w,h,title),
	//quit_button2(Point(x_max()-70,y_max()-20), 70, 20, "&QUIT", cb_quit2), //quit button
	initials(Point(250,300),70,20,"Initials: "),
	enter_button(Point(330,300),70,20,"ENTER", cb_enter) //enters initials
	/*dir_button(Point(300,320),105,20,"HOW TO PLAY", cb_dir),//will eventually go to directions screen
	back_button(Point(0,y_max()-20),70,20, "BACK", cb_back),
	two_button(Point(40,250), 70, 20, "&2", cb_two),
	three_button(Point(100,250), 70, 20, "&3", cb_three),
	four_button(Point(140,250), 70, 20, "&4", cb_four),
	five_button(Point(200,250), 70, 20, "&5", cb_five),
	six_button(Point(240,250), 70, 20, "&6", cb_six),
	seven_button(Point(300,250), 70, 20, "&7", cb_seven),
	eight_button(Point(340,250), 70, 20, "&8", cb_eight),
	nine_button(Point(400,250), 70, 20, "&9", cb_nine)
*/
{}
/*	Graph_lib::Window::Fl_Window::color(24);// changes window color
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
	*/


void pancake_window2::Level_button_maker(Graph_lib::Window& w) {
              vector<Button*> Level_button_vector(10);
                Callback cb_level;
                string Level_button_title;
                for (int i = 2; i <= 9; i++) {
                        switch(i) {
                                case 2: cb_level = cb_two; break;
				case 3: cb_level = cb_three; break;
				case 4: cb_level = cb_four; break;
				case 5: cb_level = cb_five; break;
				case 6: cb_level = cb_six; break;
				case 7: cb_level = cb_seven; break;
				case 8: cb_level = cb_eight; break;
				case 9: cb_level = cb_nine; break;
                        }
                        Level_button_title = "Level " + std::to_string(i);
                        Level_button_vector[i] = new Button(Point(7+60*(i-1),350), 60, 20, Level_button_title, cb_level);
                        w.attach(*(Level_button_vector[i]));
                }
}


		
void pancake_window2::Flip_button_maker(Graph_lib::Window& w, int level) {
              vector<Button*> Flip_button_vector(10);
                Callback cb_flip;
                string Flip_button_title;
                for (int i = 1; i <= level; i++) {
                        switch(i) {
				case 1: cb_flip = cb_one; break;
                                case 2: cb_flip = cb_two; break;
                                case 3: cb_flip = cb_three; break;
                                case 4: cb_flip = cb_four; break;
                                case 5: cb_flip = cb_five; break;
                                case 6: cb_flip = cb_six; break;
                                case 7: cb_flip = cb_seven; break;
                                case 8: cb_flip = cb_eight; break;
                                case 9: cb_flip = cb_nine; break;
                        }
                        Flip_button_title = "Flip under " + std::to_string(i);
                        Flip_button_vector[i] = new Button(Point(420, 335-20*(i+1)), 90, 20, Flip_button_title, cb_flip);
                        w.attach(*(Flip_button_vector[i]));
	}
}

void pancake_window2::display_high_scores()
{
    HighScore scores = HighScore();
    stringstream column_header;
    Text* title = new Text(Point(30,30),"High Scores");
    text.clear();
    text.push_back(title);
    column_header << "Name" << setw(20) << "Score";
    attach(*(title));
    if(scores.get_high_scores().size() > 0)
    {
        vector<Score> score_vector = scores.get_high_scores();
        Text* header = new Text(Point(30,60),column_header.str());
        text_scores.push_back(header);
	attach(*(header));
        Text* t;// = new Text(Point(30,30), "hi!");
        stringstream s;
        cout << "Score Size: " << score_vector.size() <<  "\n";
        for(int i = 0; i< score_vector.size(); ++i)
        {
            s.str(string());
            s.clear();
            s << score_vector[i].get_name() << "                 " << score_vector[i].get_score();
            t = new Text(Point(30, 90 + i*30),s.str());
                text.push_back(t);
            attach(*(text_scores[i]));
        }
        //wait_for_button();
        //detach(header);
        //for(int i = 0; i< text_scores.size(); ++i)
        //    detach(*(text_scores[i]));
    }
    else
    {
        Text* no_score = new Text(Point(30,60),"No Scores Yet");
        text.push_back(no_score);
	attach(*(no_score));
        //wait_for_button();
        //detach(no_score);
        //detach(title);
    }

}

void pancake_window2::detach_high_scores()
{
	for(auto t: text)
		detach(*t);
}

void attach_rules()
{
	Text Rules(Point(50,200), "Rules are for nerds make sure to cp for reasons on the last slide");
	
}
//int pancake_window2::wait_for_button()
//{	
//	//pancake_window2 cow(Point(200,200),200,200,"cow");
//	button_pressed = 0;
//	while(button_pressed == 0)
//	Fl::wait();
//	cout << button_pressed << endl;
//	return button_pressed;
//}
//------------------------------------------------------------------------------
void pancake_window2::cb_quit2(Address, Address pw) {
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
	player_initials = initials.get_string();
	detach_high_scores();
	detach(initials);
	detach(enter_button);
	gui_main();
}
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

void pancake_window2::cb_one(Address, Address pw)
{
        reference_to<pancake_window2>(pw).two();
}
void  pancake_window2::one()
{       bool button_pushed = true;
        button_pressed = 1;
        hide();

        //gui_main();
}

//--------------------------------------

void pancake_window2::cb_two(Address, Address pw)
{
	reference_to<pancake_window2>(pw).two();
}
void  pancake_window2::two() 
{	bool button_pushed = true;
	button_pressed = 2;
	hide();

	//gui_main();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void pancake_window2::cb_three(Address, Address pw)
{
	reference_to<pancake_window2>(pw).three();
}
void pancake_window2::three() 
{
	bool button_pushed = true;
	button_pressed = 3;
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
	button_pressed = 4;
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
	button_pressed = 5;
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
	button_pressed = 6;
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
	button_pressed = 7;
	//hide();
	cout << "7" << endl;
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
	button_pressed = 8;
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
	button_pressed = 9;
	hide();

gui_main();
}

void pancake_window2::cb_view_high_scores(Address, Address pw)
{
	reference_to<pancake_window2>(pw).view_high_scores();
}

void pancake_window2::view_high_scores()
{
	display_high_scores();
}

/*int main()
try {
pancake_window2 win{Point{100,100},600,400,"Pancake"};
return gui_main();
}
catch(exception& e) {
cerr << "exception: " << e.what() << '\n';
return 1;
}
catch ( ..) {
cerr << "Some exception\n";


}*/
