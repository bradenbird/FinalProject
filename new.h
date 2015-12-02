struct Pancake : Shape {
	vector<Ellipse*> pancakes;
        vector<Ellipse*> Pancake_Maker(int level) {
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
        ~Pancake() {
                for (int i = 0; i < pancakes.size(); ++i)
                {
                        delete pancakes[i];
                }
        }
};

