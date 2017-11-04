/*!
\mainpage Neuron Project
*
* \section intro_sec Introduction
	* This project has the final goal of simulation a network of 12500 neurons. However, it is composed of several steps
	* in order to reach that final goal. 
	* 
	* The first step was to implement the \ref Neuron class. 
	* 
	* Then, two neurons had to be created and a connection installed between them, meaning whenever one spiked, the other
	* is supposed to receive a signal straight away. Note that only the first neuron received an input from the outside,
	* therefore the second neuron's potential stayed at 0 until a signal was received. When the signal was received, 
	* the second neuron's membrane potential will decrease exponentially.
	* 
	* Next, a certain delay was implemented, as the second neuron is not supposed to receive the signal straight away. This 
	* delay was implemented with the help of a ring buffer: a vector of a fixed size (delay_steps+1), keeping track
	* of all spikes received at a certain time step. Note that this buffer was implemented with modulos in this step.
	* 
	* Finally, the idea was to create a \ref Network class, having 12500 neurons. Within those neurons, 10000 were excitatory
	* and 2500 were inhibitory. For simplicity reasons, the first 10000 neurons in my network were excitatory, and the
	* rest inhibitory. Each neuron must receive 10% input: meaning it has to have 1250 connections with other neurons in
	* the network, from which 1000 are excitatory connections and 250 inhibitory. 
	*  Please note that this buffer, in my project, was implemented in the following 
	* way: in order to get rid of modulos, slowing down my program, the class \ref Network contains two indexes which iterate on
	* each neuron's buffer at each time step: one index corresponds to the time of the network, and the second one takes
	* into consideration the delay: it starts at the index delay_steps. This way, the two indexes are always delay_steps apart
	* from each other.
	* 


*/
