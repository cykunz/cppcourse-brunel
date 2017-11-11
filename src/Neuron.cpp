#include <iostream>
#include <cmath>
#include "Neuron.hpp"
#include <vector>
#include <cassert>

using namespace std;

Neuron::Neuron(	bool excitatory, double input, vector<unsigned int> linked, vector<double> time, 
				double potential, unsigned int present, vector<double> b, unsigned int refract)
	: 	excitatory_(excitatory), input_(input), linked_neurons_(linked),  time_(time), membrane_potential_(potential),
		present_time_(present), buffer_(b), refractory_time_(refract)
{}

Neuron::~Neuron()
{}
/***************************************************/
/*	Getters	*/

double Neuron::getBuffer(int const& idx) const
{	
	return buffer_[idx];
}

bool Neuron::getExcitatory() const
{
	return excitatory_;
}

double Neuron::getInput() const
{	return input_;
}

vector<unsigned int> Neuron::getLinkedNeurons() const
{	return linked_neurons_;
}

double Neuron::getMembranePotential() const
{	return membrane_potential_;
}

unsigned int Neuron::getPresentTime() const
{	return present_time_;
}

unsigned int Neuron::getRefractoryTime() const
{	return refractory_time_;
}

vector<double> Neuron::getTime() const
{	return time_;
}

/***************************************************/
/*	Setters	*/
void Neuron::setBuffer(int const& idx, double const& new_value)
{
	buffer_[idx]=new_value;
}

void Neuron::setExcitatory(bool const& excit)
{	excitatory_=excit;
}

void Neuron::setInput(double const& input)
{	input_=input;
}

void Neuron::setMembranePotential(double const& new_potential)
{	membrane_potential_=new_potential;
}

void Neuron::setPresentTime(unsigned int const& new_present)
{	present_time_=new_present;
}

void Neuron::setRefractoryTime(unsigned int const& new_refract)
{	refractory_time_=new_refract;
}

void Neuron::setTime(vector<double> const& new_time)
{	time_=new_time;
}

/***************************************************/

void Neuron::addLink(unsigned int const& neuron)
{	/*	Adds the index of a neuron to the list of neurons linked.	*/
	linked_neurons_.push_back(neuron);
}

void Neuron::addTimeValue(int const& new_time_value)
{	/*	Adds the time at which a spike occured.	*/
	time_.push_back(new_time_value*dt);
}

double Neuron::MembranePotentialEquation(double const& amplitude) const
{	
	
	/*	Equation based on the differential equation for the evolution of the neuron's membrane
	 * 	potential. */
	return (membrane_potential_*C)+(input_*D)+(amplitude);
}

void Neuron::receive(unsigned int const& to_write, double const& amplitude)
{	
	/*	The spike is saved at an index of to_write in the buffer. */
	buffer_[to_write]+=amplitude;
}
void Neuron::showTimeValues() const
{	/*	Shows the value of the times at which each neuron spiked in the terminal.	*/	
	if(!time_.empty()){
		for(size_t i(0); i<time_.size(); ++i)
		{	
			cout<<"Spike n°"<<i+1<<"	: "<< time_[i]<<endl;
			
		}
		cout<<"Total of "<<time_.size();
			if(time_.size()==1)
			{	cout<<" spike.";
			} else {
			cout<<" spikes.";
			} cout<<endl;
	} else { 
		cout<<"No value present."<<endl;
	}
	
}

bool Neuron::update(unsigned int const& randomspikes, unsigned int const& to_read)
{	/*	Will record if the neuron spikes or not.	*/
	bool spike(false);
	/*	If the neuron is still in his refractory period...	*/
	 if(refractory_time_>0)
	 {	
		 /*	Its membrane potential is reset, and the refractory time decrements.	*/
		 membrane_potential_=MembraneReset;
		--refractory_time_;
	} else if (membrane_potential_>MembraneThreshold)
	{	/*	If the neuron's membrane potential reaches the threshold, it spikes by definition.	*/
		spike=true;
		/*	The spike time is saved, and the neuron is refractory. Its refractory time remaining is 
		 * 	set to the refractory period - 1.	*/
		addTimeValue(present_time_);
		refractory_time_=RefractoryPeriod-1;
	} else {
		/*	If the neuron isn't refractory and its potential hasn't reached the threshold,
		 * 	its membrane potential evolves with the differential equation characterizing the
		 * 	membrane potential evolution over time.	*/
			membrane_potential_=MembranePotentialEquation(buffer_[to_read]+(randomspikes*Amplitude));
	}
	 
	 	
	 /*		We reset the buffer at index to_read to 0.	*/
	 buffer_[to_read]=0;
	 
	 /*	We add a time step to the present time.	*/
	++present_time_;
	 return spike;
 }
	
	
