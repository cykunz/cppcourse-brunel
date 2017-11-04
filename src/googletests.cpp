#include <iostream>
#include "Neuron.hpp"
#include "Network.hpp"
#include "gtest/gtest.h"

TEST (NeuronTest, MembranePotential) {
	/*	We test if the membrane potential value equals the value of the equation
	 *  used after 1 time step update.	*/
	Neuron neuron;
	neuron.setInput(1.0);
	
	
	neuron.update(0, 0);
	EXPECT_EQ(20.0*(1.0-std::exp(-0.1/20.0)), neuron.getMembranePotential());
}
TEST(NeuronTest, NumberSpikesWithoutInput) {
	/*	We check if there are spikes without input (there shouldn't be).	*/
	/*	Creation of a network without the 12500 neurons initialization and without random spikes.	*/
	Neuron neuron1, neuron2;
	Network network(false, false);
	
	/*	Addition of the two neurons wanting to be tested.	 */
	network.setNeurons(vector<Neuron*>{new Neuron(neuron1), new Neuron(neuron2)});
	network.createLink(vector<unsigned int>{0,1});
	
	/*	Update of the network of 100 milliseconds.	*/
	network.update(100);

	/*	We expect no spikes recorded and a membrane potential near 0.	*/
	EXPECT_EQ(0, network.getNeurons()[0]->getTime().size());
	EXPECT_NEAR(0, network.getNeurons()[0]->getMembranePotential(), 1e-3);
}
	
TEST(NeuronTest, NumberSpikesWithInput1 /*	1	*/) {
	/*	We expect no spikes when the input is 1, and the membrane potential should tend to 20.	*/
	Neuron neuron1;
	neuron1.setInput(1.0);
	
	/*	Network  without 12500 neurons nor background noise.	*/
	Network network(false, false);
	network.setNeurons(vector<Neuron*> {new Neuron(neuron1)});
	
	network.update(1000);
	
	/*	No spikes expected.	*/
	EXPECT_EQ(0, network.getNeurons()[0]->getTime().size());
	EXPECT_GT(1e-3, std::fabs(19.999-network.getNeurons()[0]->getMembranePotential()));
}
TEST(NeuronTest, NumberSpikesWithInput2 /*	1.01	*/ ) {
	/*	We check if the spikes arrive at the correct time and if there 
	 * 	are the correct number of them.	*/
	Neuron neuron1, neuron2;
	Network network(false, false);
	network.setNeurons(vector<Neuron*>{new Neuron(neuron1), new Neuron(neuron2)});
	network.getNeurons()[0]->setInput(1.01);
	network.createLink(vector<unsigned int>{0,1});
	network.update(400);
	
	/*	We expect 4 spikes within an interval of time of 400 milliseconds.	*/
	EXPECT_EQ(4, network.getNeurons()[0]->getTime().size());
		
	EXPECT_NEAR(92.3, network.getNeurons()[0]->getTime()[0], 92.5);
	EXPECT_NEAR(186.7, network.getNeurons()[0]->getTime()[1],186.9 );
	EXPECT_NEAR(281.1, network.getNeurons()[0]->getTime()[2], 281.3);
	EXPECT_NEAR(375.5, network.getNeurons()[0]->getTime()[3], 375.7);
}
TEST(NetworkTest, WithoutSpikes)
{	/*	We check that the spike does not get transmitted if the first neuron
		doesn't spike.	*/
	Neuron neuron1, neuron2;
	neuron1.setInput(1.01);
	Network network(false, false);
	network.setNeurons(vector<Neuron*>{new Neuron(neuron1), new Neuron(neuron2)});
	network.createLink(vector<unsigned int>{0,1});
	
	/*	We update at Delay after the first spike time of neuron1. */
	network.update(92.5+Delay);
	
	/*	The first neuron should have spiked once.	*/
	EXPECT_EQ(1, network.getNeurons()[0]->getTime().size());
	
	/*	The second neuron's potential should  0.1, the amplitude, meaning it has 
	 * 	received the signal from neuron 1.	*/
	EXPECT_EQ(0.1, network.getNeurons()[1]->getMembranePotential());
}
TEST(NetworkTest, WithSpikes)
{	/*	We connect two neurons in the network, and see if the spike from neuron1 gets transmitted
		to neuron2.	*/
	Neuron neuron1, neuron2;
	Network network(false, false);
	network.setNeurons(vector<Neuron*>{new Neuron(neuron1), new Neuron(neuron2)});
	network.getNeurons()[0]->setInput(1.01);
	network.createLink(vector<unsigned int>{0,1});
	
	/*	We update at Delay after the second spike time of neuron1. */
	network.update(186.9+Delay);
	
	/*	The neuron2 should not have spiked since its membrane potential will diminish exponentially
	 * 	after receiving the signal and neuron1 should have spiked twice.	*/
	EXPECT_EQ(2, network.getNeurons()[0]->getTime().size());
	EXPECT_EQ(0, network.getNeurons()[1]->getTime().size());
}
TEST(NetworkTest, WithSpikes2)
{	/*This test will see if the delay from the ring buffer is installed correctly.	*/
	Neuron neuron1, neuron2;
	Network network(false, false);
	network.setNeurons(vector<Neuron*>{new Neuron(neuron1), new Neuron(neuron2)});
	network.getNeurons()[0]->setInput(1.01);
	network.createLink(vector<unsigned int>{0,1});
	
	network.update(92.5);
	
	/*	The buffer at the time of the spike should be equal to 0, and the one after delay_step should
	 * 	equal the amplitude transmitted by the neuron that spiked.	*/
	EXPECT_EQ(0.0, network.getNeurons()[1]->getBuffer(924%(delay_steps+1)));
	EXPECT_EQ(Amplitude, network.getNeurons()[1]->getBuffer((924+delay_steps)%(delay_steps+1)));
}

TEST(AllNeuronsTest, NumberNeurons)
{	/*	A test verifying that there are 12500 neurons in the network.	*/
	Network network(true, true);
	EXPECT_EQ(TotalNeurons, network.getNeurons().size());
}

TEST(AllNeuronsTest, NumberConnections)
{	/*	This test verifies that each neuron has exactly 1250 connections.	*/
	Network network(true, true);
	EXPECT_EQ(TotalConnections, network.getLinks()[0].size());
	
}

int main(int argc, char **argv) 
{
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
}
