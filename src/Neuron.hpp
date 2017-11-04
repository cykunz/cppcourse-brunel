#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <math.h>
#include "Utility/Constants.hpp"
#include <array>

using namespace std;

//! Neuron class
/*!	Class representing an individual neuron.	*/
class Neuron {
	private:	
		/*!	The neuron is characterized by its membrane potential,
		 * 	number of spikes, time at which the spikes occured, its present time, 
		 * 	its input, neurons it is linked to and whether it is refractory or not. 
		 * 
		 * 	Each neuron also has a ring buffer in order to put into place  a delay. Indeed,
		 * 	when a neuron receives a spike, it will only be saved in the ring buffer after
		 * 	a delay of delay_steps.	*/

		bool excitatory_; 						/**<	Boolean determining if neuron is excitatory or inhibitory.		*/
		double input_;							/**<	Input received from environment.								*/
		vector<unsigned int> linked_neurons_;	/**<	Neurons linked to this current neuron.							*/
		vector<double> time_;					/**<	Record of times when a spike occured.							*/
		double membrane_potential_;				/**<	Membrane potential.												*/
		int present_time_;						/**<	Local clock of neuron.											*/
		bool is_refractory_;					/**<	Determines whether the neuron is refractory or not.				*/
		vector<double> buffer_;					/**<	 Ring buffer installing delay principle.						*/


	
	public:
		//vector<double> buffer_;	/**<	Ring buffer associated with spikes received from linked neurons.	*/
	//!	Constructor	
	/*! A neuron will not be excitatory nor refractory within initialization, will have 0 input,
	 *  and no membrane potential. It will furthermore not be linked to any neuron, nor have spike times
	 * 	recorded. Its buffer will be initialized to delay_step+1.	*/
	Neuron(	bool excitatory=false, double input=0.0, vector<unsigned int> linked=vector<unsigned int>(0),
			vector<double> time = vector<double>(0.0), double potential=0.0, int present=0, bool refractory=false,
			vector<double> b=vector<double>(delay_steps+1));
			
	//!	Destructor
	/*!	Clears the linked neurons vector of all pointers, by deleting them.	*/
	~Neuron();

/***************************************************/
	/*	Getters	*/
	//! Gets the buffer value at a certain index
	/*!	@param idx is the index at which we want to find the buffer value.	
	 * 	@return Buffer value at index.	*/
	int getBuffer(int const& idx) const;
	//! Getter of whether the neuron is excitatory or not
	/*! @return Boolean: true if it is excitatory, false if it is inhibitory. */
	bool getExcitatory() const;
	//!	Gets the input current
	/*!	@return Input current.	*/
	double getInput() const;
	//!	Gets the linked neurons
	/*!	@return Vector of pointers of the linked neurons.	*/
	vector<unsigned int> getLinkedNeurons() const;
	//!	Gets the membrane potential
	/*!	@return Membrane potential.	*/
	double getMembranePotential() const;
	//!	Gets the refractory state
	/*!	@return bool: if refractory or not.	*/
	bool getRefractory() const;
	//!	Gets the times at which spikes occurred
	/*!	@return Vector of the times at which the spikes occurred.	*/
	vector<double> getTime() const;
/***************************************************/	
	/*	Setters	*/
	//!	Sets the buffer value at a certain index
	/*!	@param	idx: Index at which we want to affect buffer.
	 * 	@param	new_value: New value wanting to be introduced. */
	void setBuffer(int const& idx, double const& new_value);
	//! Sets excitatory state or inhibitory stat
	/*!	@param excit: Bool value of excitatory state. */
	void setExcitatory(bool const& excit);
	//!	Sets the input value
	/*!	@param input: New input value. */
	void setInput(double const& input);
	//!	Sets the membrane potential
	/*!	@param	new_potential: New membrane potential.*/
	void setMembranePotential(double const& new_potential);
	//!	Sets the refractory state
	/*!	@param	is_refractory: Bool of whether it will be refractory or not.	*/
	void setRefractory(bool const& is_refractory);
	//!	Sets the vector of times of spikes
	/*!	@param	new_time: New vector of times of spikes.	*/
	void setTime(vector<double> const& new_time);

/***************************************************/
	//!A public function taking an unsigned int as an argument
	/*!	Adds the index of a neuron wanting to be linked to its list of linked neurons.
	 * 	@param neuron: Index of neuron wanting to be added to the linked neurons.		*/
	void addLink(unsigned int const& neuron);
	
	//!A public function taking an integer argument
	/*!	Adds the time at which a spike occured to the vector.
	 * 	@param new_time_value: Time at which a spike occured, wanting to be recorded.	*/
	void addTimeValue(int const& new_time_value);
	
	//!A public function taking a double as parameter
	/*!	Calculates the membrane potential depending on a certain amplitude given.
	 * 	@param amplitude: Amplitude added to membrane potential (dependent of number of spikes received).
	 *  @return double: Value of membrane potential.	*/
	double MembranePotentialEquation(double const& amplitude) const;

	//!A public function taking an integer argument
	/*!	Receives signal given by presynaptic neuron, depending on number of connections.
	 * 	@param to_write: Index of buffer at which the spike is received is recorded.
	 * 	@param amplitude: Amplitude received.	*/
	void receive(unsigned int const& to_write, double const& amplitude);

	//!A public function 
	/*! Updates the membrane potential, depending on if random spikes are wanted or not.
	 * 	@param randomspikes: Number of random spikes received.
	 * 	@param to_read: Indes at which the buffer will be read.
	 * 	@return bool: Whether there has been a spike or not. 	*/
	bool update(unsigned int const& randomspikes, unsigned int const& to_read);

};

#endif
