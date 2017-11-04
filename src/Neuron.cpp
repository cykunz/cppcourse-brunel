#include <iostream>
#include <cmath>
#include "Neuron.hpp"
#include <vector>
#include <cassert>

using namespace std;

Neuron::Neuron(	bool excitatory, double input, vector<unsigned int> linked, vector<double> time, 
				double potential, int present, bool refractory, vector<double> b)
	: 	excitatory_(excitatory), input_(input), linked_neurons_(linked),  time_(time), membrane_potential_(potential),
		present_time_(present), is_refractory_(refractory), buffer_(b)
{}

Neuron::~Neuron()
{}
/***************************************************/
/*	Getters	*/

int Neuron::getBuffer(int const& idx) const
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

double Neuron::getMembranePotential() const
{	return membrane_potential_;
}

vector<unsigned int> Neuron::getLinkedNeurons() const
{	return linked_neurons_;
}

bool Neuron::getRefractory() const
{	return is_refractory_;
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

void Neuron::setRefractory(bool const& new_refractory)
{	is_refractory_=new_refractory;
}

void Neuron::setTime(vector<double> const& new_time)
{	time_=new_time;
}

/***************************************************/

void Neuron::addLink(unsigned int const& neuron)
{	/*	Adds the index of a neuron to the list of neurons linked.	*/
	linked_neurons_.push_back(neuron);
	/*linked_neurons_[current_index_]=neuron;
	++current_index_;*/
}

void Neuron::addTimeValue(int const& new_time_value)
{	/*	Adds the time at which a spike occured.	*/
	time_.push_back(new_time_value*dt);
}

double Neuron::MembranePotentialEquation(double const& amplitude) const
{	
	
	/*	Equation based on the differential equation for the evolution of the neuron's membrane
	 * 	potential. */
	//return (getMembranePotential()*C)+(getInput()*D)+(amplitude);
	return (membrane_potential_*C)+(input_*D)+(amplitude);
}

void Neuron::receive(unsigned int const& to_write, double const& amplitude)
{	
	/*	The spike is saved at an index of to_write in the buffer. */
	buffer_[to_write]+=amplitude;
}


bool Neuron::update(unsigned int const& randomspikes, unsigned int const& to_read)
{	/*	Initialization of the spike_time to 0 (no spikes yet).	*/
	int spike_time(0);
	
	/*	Determines if there was a spike or not during this time step.	*/
	bool spike(false);

	/*	If the membrane potential is higher than the threshold, there is a spike by definition.	*/
	if(membrane_potential_>MembraneThreshold)
	{	
		/*	Sets the spike time at the present, which is when the spike occurred.	*/
		//spike_time=present_time_;
		spike_time=present_time_;
		
		/*	Adds the time at which the spike occurred to the vector corresponding.	*/
		addTimeValue(spike_time);
		
		/*	The spike value is set to true.	*/
		 spike=true;
		 
		 /*	The neuron is then in its refractory phase, and the membrane potential is set to the
		  * reset value.	*/
		 is_refractory_=true;
		 membrane_potential_=MembraneReset;
	 }
	 
	 if(is_refractory_)
	 {	
		 /*	If the present time is beyond the refractory period after the spike time, 
		  * the neuron is not refractory anymore.	*/

		if(present_time_>(spike_time+RefractoryPeriod))
		 {

		is_refractory_=false;
			}
	 } else {
		 
		 /*	If the neuron isn't refractory, then the membrane potential can be updated with the amplitude of
		  * the number of spikes in the buffer at index: to_read and the random spikes given by external
		  * neurons.	*/
		 membrane_potential_=MembranePotentialEquation(buffer_[to_read]+(randomspikes*Amplitude));
	 }
	 
	 
	 	
	 /*		We reset the buffer at index to_read to 0.	*/
	 buffer_[to_read]=0;
	 
	 /*	We add a time step to the present time.	*/
	++present_time_;
	 return spike;
 }
	
	
