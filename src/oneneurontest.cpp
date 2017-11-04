
#include "Network.hpp"
#include <iostream>

using namespace std;

int main()
{	/*	The terminal enters the values for external current and simulation time.	*/
	cout<<"Enter the value of the external current for the first neuron: ";

	double input(0.0);

	cin>>input;
	
	double time(0);
	cout<<"Enter the value of the time interval :";
	do{	cin>>time;
	} while(time<0.0);

	Neuron neuron1; /*	Initialization of a neuron.	*/
	neuron1.setInput(input);
	Network network(false, false);
	network.setNeurons(vector<Neuron*>{new Neuron(neuron1)});
    network.update(time); /*	Update of the membrane potential.	*/
	network.getNeurons()[0]->showTimeValues();	/*	Shows the spike time values to show the evolution of the membrane potential.	*/

	
	return 0;
}
