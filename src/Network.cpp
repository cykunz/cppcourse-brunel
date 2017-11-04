#include "Network.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

Network::Network(	bool all, bool random, vector<Neuron*> new_neur, unsigned int clock, unsigned int read, unsigned int write)

	: 				all_(all), random_wanted_(random), neurons_(new_neur), clock_time_(clock), index_read_(read), 
					index_write_(write)
		
{		/*	Random devices useful to calculate the random connectivity of neurons.	*/
		random_device rd;
		generator=mt19937(rd());
		distribution=poisson_distribution<unsigned int>(ExternalFrequency*dt);
		
		/*	Opening of file to contain number of spikes at each dt step.	*/
		file.open("spikes.txt");
		assert(!file.fail());
		
		/*	Opening of file to contain id of neurons having spiked at each dt step.	*/
		f.open("jupyterplot.txt");
		assert(!f.fail());
		
	/*	If the user wishes to have all 12500 neurons in the network, these are added the following way:
	 * 	for simplicity reasons, the first 10000 neurons will be excitatory and the rest will be 
	 * 	inhibitory. Then, random connections are established, from which 1000 are excitatory connections,
	 * 	and 250 are inhibitory.	*/
	if(all_)
	{	
		/*	The matrix of links between neurons is initialized to a size of 12500 by 1250, since every
		 * 	neuron is required to have 1250 connections.	*/
		links_=vector<vector<unsigned int>>(TotalNeurons, vector<unsigned int>(TotalConnections));
		
		/*	The vector containing all neurons is resized to 12500.	*/
		neurons_.resize(TotalNeurons);
		
		/*	Addition of 10000 excitatory neurons,
		 * 	and 2500 inhibitory neurons to the network.	*/
		for(size_t i(0);i<TotalNeurons;++i)
		{	
			bool excit(false);
			/*	The first 10000 neurons are excitatory.	*/
			if(i<NumberExcitatoryNeurons)
			{	excit=true;
			}
			neurons_[i]=new Neuron(excit);
		}
		/*	We initialize the connections within the network. These are generated randomly. */
		initializeConnections();
	}
	
}

Network::~Network()
{	/*	The destructor sets all neurons to nullptr, deletes them,
		and clears the vector.	*/

	clearNeurons();
	
	/*	Closing all files used to store values.	*/
	f.close();
	file.close();
}
/***************************************************/
/*	Getters	*/

unsigned int Network::getClockTime() const
{	return clock_time_;
}

vector<Neuron*> Network::getNeurons() const
{	return neurons_;
}

matrix Network::getLinks() const
{	return links_;
}
/***************************************************/
/*	Setters	*/

void Network::setClockTime(unsigned int const& new_time)
{	clock_time_=new_time;
}

void Network::setNeurons(vector<Neuron*> const& new_neurons)
{	/*	Before affecting new pointers, clears the vector.	*/
	clearNeurons();
	for(size_t i(0);i<new_neurons.size();++i)
	{	
		/*	The new pointers on Neurons are added to the vector.	*/
		neurons_.push_back(new_neurons[i]);
	}
}


/***************************************************/
void Network::addNeuron(Neuron* neuron_to_add)
{	/*	Adds a neuron to the vector of neurons in the network.	*/
	neurons_.push_back(neuron_to_add);
}

void Network::clearNeurons()
{	/*	First sets all pointers to nullptr and deletes them.	*/
	for(size_t i(0);i<neurons_.size();++i)
	{	neurons_[i]=nullptr;
		delete neurons_[i];
	}
	
	/*	It will leave an empty vector with a size of 0.	*/
	neurons_.clear();
}

void Network::createLink(vector<unsigned int> neurons_to_link)
{	
	/*	Verifies if the vector given is empty or not.	*/
	assert(!neurons_to_link.empty());
	
	/*	Verifies that the vector given doesn't contain a single neuron, 
	 *  in which case the link wouldn't make sense. 	*/
	assert(neurons_to_link.size()>1);
	
	/*	Iteration in all neurons in the list given.	*/
	for(size_t i(0);i<neurons_to_link.size()-1;++i)
	{	

				
				/*	For each neuron, we have to iterate in the rest of the list
				 * 	in order to add the present neuron to each list of linked_neurons_.	*/
				for(size_t j(i+1);j<neurons_to_link.size();++j)
				{		
					/*	Declaration of variables to simplify comprehension of code.	*/
						unsigned int adds(neurons_to_link[i]);
						unsigned int added(neurons_to_link[j]);
						
						/*	Neuron i adds neuron j to its list of neurons (unilateral connection). 	*/
						neurons_[adds]->addLink(added);
	
				}
		
	}

}

void Network::initializeConnections()
{	
	/*	Iteration in all neurons, since each of them need to be connected to other neurons.	*/
	for(size_t i(0);i<TotalNeurons;++i)
	{	

		/*	Each neuron receives an input of 10% from all other neurons, from which 1000 connections
		 * 	are excitatory and 250 are inhibitory.	*/
		for(size_t j(0);j<TotalConnections;++j)
		{	
			/*	Call of the method uniform to chose a random integer.	*/
			if(j<NumberExcitatoryConnections)
			{	
				/*	The link can be any excitatory neuron. */
				links_[i][j]=uniform(0, NumberExcitatoryNeurons);
			}else{
				
				/*	The link can be any inhibitory neuron.	*/
				links_[i][j]=uniform(NumberExcitatoryNeurons, TotalNeurons);
			}
		}
	}
}
	

unsigned int Network::uniform(unsigned int const& min, unsigned int const& max)
{	
	/*	Use of uniform_int_distribution to generate a random integer between min and max.	*/
	uniform_int_distribution<unsigned int> uni(min, max-1);
	
	return uni(generator);
}
unsigned int Network::randomSpikes()
{	
	/*	Use of poisson generator to generate a random integer. 	*/
	return distribution(generator);
}
void Network::update(double const& endtime)
{	
	/*	Conversion of the time given in time steps.	*/
	unsigned int end(endtime/dt);
	
	/*	Initialization of the number of spikes and the number of random spikes to 0.	*/
	unsigned int number_spikes(0);
	unsigned int randomspikes(0);

	/*	While the clock time is within the interval...	*/
	while(clock_time_<end)
	{		
		/*	Verifies if there are neurons in the network.	*/
		assert(!neurons_.empty());
		
			/*	Iteration in all neurons contained in the network.	*/
			for(size_t i(0);i<neurons_.size();++i)
			{	
				/*	If random spikes are wanted, we use the poisson distribution. */
				if(random_wanted_)
				{	randomspikes=randomSpikes(); 
				}
				
				/*	If neuron i spikes, it will transmit its signal to all the neurons it is linked to (found in the 
				 * 	matrix links_). */
				if(neurons_[i]->update(randomspikes, index_read_))
				{	
					/*	The number of spikes increments.	*/
					++number_spikes;
					
					/*	Depending on whether the user considers all 12500 neurons or not, the update method will
					 * 	slightly change.	*/
					if(all_)
					{	
						/*	The file conserves the neuron id and the particular time at which the spike
						 * 	occurred.	*/
							f<<clock_time_<<" "<<i<<endl;
							
						/*	As previously explained, we need to transmit the signal of the spiked neurons to
						 * 	the neurons it is linked to: this is done by iterating in the matrix. */	
							for(size_t j(0);j<TotalConnections;++j)
							{	
								/*	The initialization of the matrix has been done so that all excitatory 
								 * 	neurons are within the range [0, NumberExcitatoryNeurons[, and the rest
								 * 	are inhibitory.	*/
								 
								 /*	We test if the neuron spiked is excitatory or not, in which cases the amplitudes
								  * delivered will differ: +ExcitatoryAmplitude or -InhibitoryAmplitude. 
								  * 	
								  * Each neuron will receive the spike after a certain delay, meaning at index
								  * index_write in their individual buffers.	*/
								if(i<NumberExcitatoryNeurons)
								{	
									neurons_[links_[i][j]]->receive(index_write_, ExcitatoryAmplitude);

								} else {

									neurons_[links_[i][j]]->receive(index_write_, InhibitoryAmplitude);
								}
							}
					} else {
						/*	If the amount of neurons is not of 12500 (useful for testing two neurons),
						 * 	we iterate in all the linked neurons of the neuron having spiked, and transmit
						 * 	the signal with an amplitude Amplitude.	*/
						 
						 /*	In this case, the file "jupyterplot.txt" will stock the index of the neuron having spiked and its
						  * membrane potential, which should equal to 0 since after a spike, the membrane potential is set to 0.	*/
						f<<i+1<<" "<<neurons_[i]->getMembranePotential()<<endl;
						for(auto& linked: neurons_[i]->getLinkedNeurons())
						{	
							neurons_[linked]->receive(index_write_, Amplitude);
						}
						
					}
				}
					
				}
		/*	The indexes are updated at each time step of the simulation	.*/
		updateBuffer();
		
		/*	This file keeps track of the number of spikes occurring at each time step.	*/
		 file<<clock_time_<<" "<<number_spikes<<endl;
		 
		/*	Makes the overall simulation time evolve.	*/
		++clock_time_;	
		
		/*	Reset the number of spikes.*/
		number_spikes=0;
	}	

	
}

void Network::updateBuffer()
{	/*	Incrementation of both indexes, if either goes further than the size of the buffer(delay_steps+1),
		it will be put back to 0.	*/
	++index_read_;
	if(index_read_>delay_steps)
	{	index_read_=0;
	}
	
	++index_write_;
	if(index_write_>delay_steps)
	{	index_write_=0;
	}
	
}



