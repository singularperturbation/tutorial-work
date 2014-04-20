CFLAGS=-Wall -g
# Just going to do this Makefile by hand
problems=montecarlo problem1 problem2 problem3 problem4 problem5 problem6 problem7 problem8 problem10 problem11 problem12 problem13 problem14 problem16
all: tags sources

tags:
	ctags -R ./

sources: $(problems)

montecarlo: montecarlo.c
	gcc -lm  montecarlo.c -o montecarlo

problem13: project_euler_prob13.c
	gcc project_euler_prob13.c -o problem13
	
problem14: project_euler_prob14.c
	gcc project_euler_prob14.c -o problem14

problem12: prob12_functs.c myfuncts.h project_euler_prob12.c
	gcc -lm prob12_functs.c project_euler_prob12.c -o problem12

problem1: project_euler_prob1.c
	gcc -lm project_euler_prob1.c -o problem1

problem10: project_euler_prob10.c
	gcc -lm project_euler_prob10.c -o problem10

problem11: project_euler_prob11.c
	gcc -lm project_euler_prob11.c -o problem11

problem16: project_euler_prob16.c
	gcc -lm -lgmp project_euler_prob16.c -o problem16

problem2: project_euler_prob2.c
	gcc -lm project_euler_prob2.c -o problem2

problem3: project_euler_prob3.c
	gcc -lm -lgmp project_euler_prob3.c -o problem3	

problem4: project_euler_prob4.c
	gcc -lm project_euler_prob4.c -o problem4

problem5: project_euler_prob5.c
	gcc -lm project_euler_prob5.c -o problem5

problem6: project_euler_prob6.c
	gcc -lm project_euler_prob6.c -o problem6

problem7: project_euler_prob7.c
	gcc -lm project_euler_prob7.c -o problem7

problem8: project_euler_prob8.c
	gcc -lm project_euler_prob8.c -o problem8

clean:
	rm problem*
	rm montecarlo
