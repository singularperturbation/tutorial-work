CFLAGS=-Wall -ggdb
# Just going to do this Makefile by hand

problems=montecarlo problem1 problem2 problem3 problem4 problem5 problem6 problem7 problem8 problem10 problem11 problem12 problem13 problem14 problem16 problem17 problem18 problem20

all: tags sources

tags:
	ctags -R ./ /usr/include/*.h

sources: $(addprefix bin/, $(problems))

bin/problem20: project_euler_prob20.c
	gcc -lm -lgmp project_euler_prob20.c -o bin/problem20

bin/problem18: project_euler_prob18.lua bin/problem18helper
	luajit -b project_euler_prob18.lua bin/problem18

bin/problem18helper: project_euler_prob18_helper.lua
	luajit -b project_euler_prob18_helper.lua bin/problem18helper

bin/problem17: project_euler_prob17.h project_euler_prob17_helper_functions.c project_euler_prob17.c
	gcc -std=c99 project_euler_prob17_helper_functions.c project_euler_prob17.c -o bin/problem17

bin/montecarlo: montecarlo.c
	gcc -lm montecarlo.c -o bin/montecarlo

bin/problem13: project_euler_prob13.c
	gcc project_euler_prob13.c -o bin/problem13
	
bin/problem14: project_euler_prob14.c
	gcc project_euler_prob14.c -o bin/problem14

bin/problem12: prob12_functs.c myfuncts.h project_euler_prob12.c
	gcc -lm prob12_functs.c project_euler_prob12.c -o bin/problem12

bin/problem1: project_euler_prob1.c
	gcc -lm project_euler_prob1.c -o bin/problem1

bin/problem10: project_euler_prob10.c
	gcc -lm project_euler_prob10.c -o bin/problem10

bin/problem11: project_euler_prob11.c
	gcc -lm project_euler_prob11.c -o bin/problem11

bin/problem16: project_euler_prob16.c
	gcc -lm -lgmp project_euler_prob16.c -o bin/problem16

bin/problem2: project_euler_prob2.c
	gcc -lm project_euler_prob2.c -o bin/problem2

bin/problem3: project_euler_prob3.c
	gcc -lm -lgmp project_euler_prob3.c -o bin/problem3	

bin/problem4: project_euler_prob4.c
	gcc -lm project_euler_prob4.c -o bin/problem4

bin/problem5: project_euler_prob5.c
	gcc -lm project_euler_prob5.c -o bin/problem5

bin/problem6: project_euler_prob6.c
	gcc -lm project_euler_prob6.c -o bin/problem6

bin/problem7: project_euler_prob7.c
	gcc -lm project_euler_prob7.c -o bin/problem7

bin/problem8: project_euler_prob8.c
	gcc -lm project_euler_prob8.c -o bin/problem8

clean:
	rm bin/problem*
	rm bin/montecarlo
	rm tags
