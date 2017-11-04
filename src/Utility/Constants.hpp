#ifndef CONSTANTS_H
#define CONSTANTS_H


//!	Constants needed for the calculations	*/
const double dt = 0.1; 															/**<	The time step, 0.1 milliseconds.					*/
const double MembraneThreshold =20.0;											/**<	The membrane potential threshold, 20.0 milliVolts	*/
const double MembraneReset = 0.0; 												/**<	The membrane potential reset value, 0.0 Volts.		*/
const double RefractoryPeriod = 20.0;									 		/**<	The refractory period, 20 time steps.				*/
const double Tao = 20.0;														/**<	Tao, constant to calculate resistance.				*/
const double Capacity =  1.0;													/**< 	The capacity, 1 Faraday.							*/
const double Resistance = Tao/Capacity;  										/**< 	The resistance, in Ohms.							*/
const double Amplitude= 0.1;													/**< 	The amplitude, 0.1 milliVolts.						*/
const double Delay=1.5;															/**< 	The delay, 1.5 milliseconds.						*/

const double C=exp(-dt/Tao);													/**<	Constant useful to calculate membrane potential.	*/
const double D=Resistance*(1-C);												/**< 	Constant useful to calculate membrane potential.	*/

const unsigned int delay_steps=static_cast<unsigned long>(floor(Delay/dt));		/**<	Conversion of the delay in time steps.				*/

const unsigned int TotalNeurons = 12500;										/**<	Total amount of neurons.							*/
const unsigned int NumberExcitatoryNeurons = 10000;								/**< 	Total number of excitatory neurons.					*/
const unsigned int NumberInhibitoryNeurons = 2500;								/**<	Total number of inhibitory neurons.					*/

const unsigned int TotalConnections = 1250;										/**<	Total amount of connections per neuron.				*/
const unsigned int NumberExcitatoryConnections = 1000; 							/**<	Total number of excitatory connections per neuron.	*/
const unsigned int NumberInhibitoryConnections = 250;							/**<	Total number of inhibitory connections per neuron.	*/
const unsigned int NumberExternalConnections = NumberExcitatoryConnections;		/**< 	Total number of external connections per neuron.		*/

const double g = 5.0; 																/**<	Constant useful to determine inhibitory amplitude.	*/
const double ExcitatoryAmplitude = 0.1;											/**<	Excitatory amplitude is 0.1 mV.						*/
const double InhibitoryAmplitude = -g*ExcitatoryAmplitude;						/**<	Inhibitory amplitude depends on g.					*/

const double eta = 2.0;															/**<	External frequency over threshold frequency.	 	*/
const double ExternalFrequency = (eta*MembraneThreshold)/(ExcitatoryAmplitude*Tao);	/**< Value of external frequency from external connections	*/
const double ThresholdFrequency = MembraneThreshold/(NumberExcitatoryConnections*ExcitatoryAmplitude*Tao); /**< Based on formula for the threshold frequency 	*/

#endif 
