# Permutation-Coded Evolutionary Algorithm (PcEA)

This repository contains the C source for the Permutation-Coded Evolutionary Algorithm (PcEA) solver used in the [MESS-2020+1 competition](https://www.ants-lab.it/mess2020/#competition).

Compile the solver as follows:

$> make

Run with: 

$> ./pcea-cflp-ci <input_file> <solution_file> <timeout> <random_seed>`

For example, the following command line:

$> ./pcea-cflp-ci Instances/wlp01.dzn sol01.txt 71 978675

runs the solver on input instance 'wlp01.dzn' located in the 'Instances' directory and writes the solution to 'sol01.txt'. The value of the random seed is 978675 and a timeout of 71 seconds is applied for the run.