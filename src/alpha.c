/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Main file.
*/

#include "main.h"

void find_alpha(float *alpha, float moy, float left, float right)
{
	if (left < right - 100)
		*alpha = -0.32;
	else if (left > right + 100)
		*alpha = 0.32;
	if (moy > 1000) {
		if (moy > 1600)
			*alpha = 0;
		else if (moy > 1200)
			*alpha *= 0.05;
		else
			*alpha *= 0.1;
	} else if (moy > 300) {
		if (moy > 800)
			*alpha *= 0.2;
		else if (moy > 600)
			*alpha *= 0.4;
		else
			*alpha *= 0.8;
	}
}

void set_angle(float *pos)
{
	char *c;
	char *s = malloc (5);
	char **tab;
	float alpha = 0;
	float moy = gen_moy(pos, 15, 16);
	float left = pos[0];
	float right = pos[31];

	write (1, "WHEELS_DIR:", 11);
	find_alpha(&alpha, moy, left, right);
	sprintf(s, "%.2f", alpha);
	write (1, s, 5);
	write (1, "\n", 1);
	c = my_gnl();
	check_ops(c, 1, "WHEELS_DIR");
	tab = my_str_to_word_array(c, ':');
	check_track(tab);
	free_all(tab, NULL, c);
}
