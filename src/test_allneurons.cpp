#include "Network.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{	
	/*	We ask the time of simulation wanted from the terminal.	*/
	double time(0.0);
	cout<<"Enter the value of the wanted simulation time :";
	/*	We make sure the time given isn't negative.	*/
	do{	cin>>time;
	} while(time<0.0);

	/*	In this test, we want to test all 12500 neurons (first argument=true) with background noise
	 * 	(second argument=true).	*/
	Network network(true, true);
	
	/*	We update the network with the wanted simulation time.	*/
	network.update(time);

	return 0;
}
