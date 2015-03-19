# Scheduler
Scheduler Algorithm (initially written as a part of the SLEEP protocol) - the energy efficient codewords with varying duty cycles for a wireless sensor networks.

Example code of [3,2,3] with duty cycle 66.6%
---------------------------------------------------------------------------------------------------------------------------
1 1 0 
1 0 1 
0 1 1 

Constructing a code with the following property 
[n, k, d] = [n, (d-1), d]

n = 3, k = 2 , d = 3, duty_cycle = 66.666672 % 

Where, n = length of each codeword, k = number of wakeup in a codeword, d = number of codewords, duty cycle = k / n 
---------------------------------------------------------------------------------------------------------------------------

