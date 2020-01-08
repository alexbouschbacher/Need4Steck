/*
** EPITECH PROJECT, 2017
** Project 104intersection
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <string.h>

	char **my_str_to_word_array(char *, char);
	float set_speed(float *);
	void set_angle(float *);
	float *gen_tab(char **);
	float gen_moy(float *, int, int);
	char *my_gnl(void);
	void free_all(char **, float *, char *);
	int global_track(int);
	void check_track(char **);
	void check_ops(char *, int, char *);
#endif
