#include "Network.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cout<<"Enter the value of the external current for the first neuron: ";

	double input(0.0);

	cin>>input;
	
	double time(0);
	cout<<"Enter the value of the time interval :";
	do{	cin>>time;
	} while(time<0.0);

	Neuron neuron1;
	/*	Only the first neuron receives the given external input.	*/
	neuron1.setInput(input);
	/*	The other neuron's input is 0 by default.	*/
	Neuron neuron2;
	Network network(false, false);
	
	network.setNeurons(vector<Neuron*>{ new Neuron(neuron1), new Neuron(neuron2)});
	network.createLink(vector<unsigned int>{0,1});

	network.update(time); /*	Update of the overall network.	*/
	
	/*	The first neuron should have spiked normally, since the input current it received
	 * 	is greater than 0.	*/
	cout<<"Neuron 1: "<<endl;
	network.getNeurons()[0]->showTimeValues();
	/*	The second neuron does not spike, but receives the signal.	*/
	cout<<"Neuron 2: "<<endl;
	network.getNeurons()[1]->showTimeValues();
	
	
	return 0;
}
