#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <vector>
#include "Neuron.hpp"
#include <random>
#include <fstream>

using namespace std;

typedef vector<vector<unsigned int>> matrix; /**<	Useful typedef for better comprehension of further code.	*/

//! Network class
		/*!	A network is caracterized by the neurons it contains, its global time,  the indexes to_read_ and 
		 * 	to_write_ in each neuron's buffer as well as a matrix of indexes of neurons linked.
		 * 
		 * This configuration of indexes will make both indexes evolve together, therefore making
		 * 	sure that the delay between them is always of delay_steps. Indeed, a neuron will receive its spike at 
		 * 	index_write_, which is delay_steps_ later than index_read_.		
		 * 
		 * 	The network is optimized in order to choose whether the network will contain all 12500 neurons,
		 * 	as well as whether background noise is wanted or not. */
class Network
{	
	private:

		 
	bool all_;					/**< 	Set to true if all 12500 neurons are part of the network.									*/
	bool random_wanted_;		/**<	Set to true if we want to include random spikes as background noise or not.					*/
	vector<Neuron*> neurons_;	/**< 	Vector of pointers on the neurons containted in the network.								*/
	unsigned int clock_time_;	/**<	 Global time of network.																	*/
	unsigned int index_read_;	/**<	(index_read_): Index when reading the neuron's buffer.										*/
	unsigned int index_write_;	/**<	(index_write_): Index when writing spikes (index_read+delay_steps).							*/
	matrix links_;				/**<	(links_ ):Matrix of links between neurons. 													*/
	
	/**!	The following variables are useful to generate random integers, wanted when initializing connections 
	 * 		between neurons and generating random spikes.	*/
	 
	mt19937 generator;			/**<					Mersenne twister engine. 													*/
	poisson_distribution<unsigned int> distribution; 					/**<	(distribution):	Poisson distribution 				*/
	
	/**!	The following variables enables us to have access to these files in the update method: they are opened
	 * 		in the constructor and closed in the destructor.	*/
	 
	ofstream file; 				/**<	File keeping track of the number of spikes per time step.									*/
	ofstream f;					/**<	File keeping track of the ids of neurons spiking at a time.									*/
	
	public:
	//! Constructor
	/*! By default, the vector of neurons it contains has a size of 0, the simulation time is set to 0,
	 * 	the index to read from the buffer starts at index 0, whereas the index to write starts at 
	 * 	index delay_steps.*/
	Network(	bool all, bool random, vector<Neuron*> new_neur=vector<Neuron*>(0), unsigned int clock=0,
				unsigned int read=0, unsigned int write=delay_steps);
	
	//! Destructor
	/*!	Clears the vector of neurons in the network by setting them to nullptr and deleting them.	*/
	~Network();

/***************************************************/
	/*	Getters	*/
	//! Gets the clock time (simulation time)
	/*!	@return : Simulation time, as a dt step.	*/
	unsigned int getClockTime() const;
	//! Gets the neurons in the network
	/*!	@return Vector of pointers on neurons.	*/
	vector<Neuron*> getNeurons() const;
	//! Gets the matrix of links in the network
	/*! @return Matrix of links	*/
	matrix getLinks() const;
/***************************************************/
	/*	Setters	*/
	//!	Sets the clock time
	/*!	@param	new_time: New value for the clock time. */
	void setClockTime(unsigned int const& new_time);
	//!	Sets the neurons in the network
	/*!	@param	new_neurons: New vector of neurons wanting to be part of the network. */
	void setNeurons(vector<Neuron*> const& new_neurons);

/***************************************************/
	//!A public function taking a Neuron pointer as parameter
	/**! Adds a neuron to the list of neurons in the network.
	 * @param neuron_to_add: Pointer on a neuron	*/
	 void addNeuron(Neuron* neuron_to_add);
	 
	//!A public function
	/*!	Clears the vector of all neurons in the network.*/
	void clearNeurons();
	
	//!A public function taking vector of pointers on neurons as a parameter
	/*!	Links all neurons in the vector given with respective weights. 
	 * 	This method was mostly used to link 2 neurons.
	 * 	@param neurons_to_link: Vector of unsigned integers with indexes of neurons wanting to be linked.*/
	void createLink(vector<unsigned int> neurons_to_link);

	//!A public function
	/*! Initializes the matrix of connections in the network.	*/
	void initializeConnections();
	
	//!A public function taking two unsigned int as parameters.
	/*! Generates a random integer between min and max.
	 * 	@param min: Minimum limit of value wanting to be generated.
	 * 	@param max: Maximum limit of value wanting to be generated.
	 * 	@return unsigned int: Random integer between min and max.	*/
	unsigned int uniform(unsigned int const& min, unsigned int const& max);
	
	//!A public function
	/*! Gives a certain number of spikes generated randomly from external neurons, with a 
	 * 	poisson distribution.
	 * 	@return unsigned integer: Number of spikes.	*/
	unsigned int randomSpikes();
	
	
	//!A public function taking a double argument
	/*!	Method updating all neurons in the network, passing on the spike signal in case of spike.	
	 * 	@param endtime: Time at which simulation ends.*/
	void update(double const& endtime);
	
	//!A public function
	/*!	Method updating the indexes to read and to write. s*/
	void updateBuffer();
	
};
#endif
