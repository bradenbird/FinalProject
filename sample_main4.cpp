#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
//#include <vector>
//#include <vector>

Vector_ref<Ellipse> Pancake_Maker(int level) {
//	Vector_ref<Ellipse> pancake(9);
	Vector_ref<Ellipse> pancake;
	for (int i = 0; i < level; i++) {
		Ellipse temp(Point(300, 300-20*i), 100-3i, 20);
		pancake.push_back(temp);
//		pancake[i] = Ellipse(Point(300, 300-20*i), 20, 100-3*i);
	
//		cout << 
//		return pancake;
	}
	return pancake;
}

int main()
try {
  Vector_ref<Ellipse> Pancakes;
  if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);
  Simple_window win1(Point(100,200),600,400,"two lines");
  Line horizontal(Point(100,100),Point(200,100));  // make a horizontal line

  Pancakes = Pancake_Maker(8);
//  Pancakes.push_back(new Ellipse(Point (300, 300), 20, 100));

//  cout << Pancakes.size() << endl;

  //win1.attach(*Pancakes[0]);

//  for(int i = 0; i < Pancakes.size(); i++) {
    win1.attach((Pancakes[0]));
//  }
  Line vertical(Point(150,50),Point(150,150));     // make a vertical line
//  vertical.set_style(Line_style(Line_style::solid, 1));
  win1.attach(horizontal);
  win1.attach(vertical);
  vertical.set_color(Color::magenta);
  cout << "here" << flush << endl;
  win1.wait_for_button();
  vector<int> my_int {0, 1, 2};
  
//!!!!!!!!!!!!!!!!!!!!!!!!!!!EXAMPLE SWAP!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
  // int temp = my_int[0];
  //my_int[0] = my_int[2];
  /my_int[2] = temp;

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
