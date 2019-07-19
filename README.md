# Bicolor_Towers_Of_Hanoi
Solution implemented in C, Prolog and Scheme
Bicolor Tower of Hanoi solution implemented in C, Prolog and Scheme.
The bicolor towers of Hanoi problem is a variation of traditional towers of Hanoi problem. (It was offered to grade 3-6 students at 2' eme Championnat de Francedes Jeux Math ́ematiques et Logiquesheld in July 1988). Suppose there arethree pegs, A, B and C. Suppose there are two sets of disks α and β, where α={αi | 1 <= i <= n } and β = {βi | 1 <= i <= n} such that color of everydisk in α is blue and color of every disk in β is red.
The goal of the problem is to make the towersof pegs A and B monochrome. The biggest disks at the bottom of thepegs Aand B are required to swap positions. 

The initial configuration is like:

![Screenshot from 2019-07-19 17-48-24](https://user-images.githubusercontent.com/40428406/61548231-7eea5180-aa4d-11e9-9aa4-2d81c8277dfb.png)


The final configuration is like:

![Screenshot from 2019-07-19 17-48-31](https://user-images.githubusercontent.com/40428406/61548236-83166f00-aa4d-11e9-880e-05db3a1fc078.png)


The rules of the problem are the same of Hanoi:

	1) Only one disk can be moved at any time.

	2) At no time can a larger disk be placed on a smaller disk. Same size diskscan be placed over one another.


##C
**Imperative Programming**
Just compile and run the code, initially it will ask you how many disks it has to consider, so if you type 10 it will put 5 disks for the first and the second pegs.
In the standard output you will see the list of movements and a graphical representation of the system:


##Prolog
**Logic Programming**
To "run" the code just: 
	1. Open an interpreter
	2. Compile the code with: ***consult(‘bicolorHanoi_prolog.pl’).***
	3. Type for example: ***hanoi_bicolore(-1, 8, 'A', 'B', 'C').***
You will see the list of move printed in the output file, with the format **X,Y** where **X** is the source peg and **Y** is the destination peg. So you example **A,C** means **move the disk from A to C**


##Scheme
**Functional Programming**
To "run" the code just: 
	1. Open an interpreter, like Dr.Racket
	2. Compile the code
	3. Type for example: ***(hanoi_bicolore -1 4 "A" "B" "C")***
You will see the list of move printed in the output file


##Extra
I implmented a C program (extra.c) that takes in input from a file the list of movements and prints in the standart output the system configuration at every shifts (like the C code output). The input file must contain the move in this format: **A,C** that mean move from **A** to **B**. One movement for each line.


