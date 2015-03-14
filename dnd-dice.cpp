#include <iostream>
#include <cstdlib>
#include <random>
#include <functional>
using namespace std;

int main(int argc, char **argv) {
	int dicetoroll, times, result, i;
	bool forced;
	forced = false;
	if(argc <= 1) {
		cerr << "No arguments given!" << endl;
		return 1;
	} else {
		dicetoroll = atoi(argv[1]);
		if(argc >= 3)
			times = atoi(argv[2]);
		else times = 1;
		if(argc >= 4)
			forced = (argv[3][0] == 'f');
		if(dicetoroll != 20 && dicetoroll != 2 && dicetoroll != 4 && dicetoroll != 6 && dicetoroll != 100 && dicetoroll != 10 &&  !forced) {
			cerr << "Not expecting dice " << dicetoroll << ", if you really meant it please use `dnd-dice <dice> <nrtimes> f`" << endl;
			return 2;
		}
		cout << "Rolling " << times << "d" << dicetoroll << "\n";
		std::random_device rd;
		default_random_engine generator(rd());
		uniform_int_distribution<int> distribution(1, dicetoroll);
		auto dice = bind(distribution, generator);
		result = 0;
		i = times;
		while(i) {
			i--;
			result += dice();
		}
		cout << "You got " << result;
		if(result == times)
			cout << ", CRITICAL FAILURE";
		else if(result == dicetoroll * times)
			cout << ", CRITICAL SUCCESS";
		else if(result > (dicetoroll * times / 2))
			cout << ", on the good side";
		else cout << ", ouch";
		cout << endl;
	}
	return 0;
}
