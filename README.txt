# cppcourse-brunel
Neuron project SVBA3
 A. Program presentation: 
The Introduction to this project is in src/html/index.html

B. Program compilation 

In the terminal, go to src. Please make sure you delete the file "CMakeCache.txt" in src in order to execute correctly.
1- Type in "cmake .." 
2- Type in "make" 
To launch overall program with 12500 neurons: 
  3- Type in "./AllNeurons" and set the simulation time to 100 (ideal). 
To launch google tests: 
  3- Type in "./googletests"

C. Program Uses 

This program is based on the "Brunel" paperwork. All constants are in "src/Utility/Constants.hpp".

For HTML documentation: 
-index.html is the introduction to this project. 
-classNetwork.html documents the class Network. 
-classNeuron.html documents the class Neuron. 
-classNeuron/Network-members.html contains all member functions of respective class. 
-files.html gives access to both classes. 
-Class variables can be accessed with functions_vars.html 
-Source documents can be accessed with Network/Neuron_8hpp_source.html

In the directory "Plots" are plots with different g and eta values to illustrate Figure 8 a to d in the "Brunel" paperwork.
All files "..._ file1" have been generated with gnuplot. 
Gnuplot can be launched from terminal by writing: 
    1- gnuplot 
   2- plot "spikes.txt" using 1:2 with boxes 
All files "..._ file2" have been generated using an online plotter: https://cs116-plot.antoinealb.net/.

Furthermore, I have included the tests from the other weeks:
To run the test with one neuron, type ./OneNeuron
To run the test of the buffer with two neurons, type ./Buffer
Please note that the file entitled "jupyterplot" will in this case contain the membrane potential of each neuron.

