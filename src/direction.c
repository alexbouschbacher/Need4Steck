/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Main file.
*/

#include "main.h"

float set_speed(float *pos)
{
	char *c;
	char *s = malloc (4);
	char **tab;
	float mid = gen_moy(pos, 15, 16);
	float speed = (mid / 4000 * 2.5 > 1) ? 1 : mid / 4000 * 2.5;

	sprintf(s, "%.2f", speed);
	write(1, "CAR_FORWARD:", 12);
	write(1, s, 4);
	write(1, "\n", 1);
	c = my_gnl();
	check_ops(c, 1, "CAR_FORWARD");
	tab = my_str_to_word_array(c, ':');
	check_track(tab);
	free_all(tab, NULL, c);
	if (speed < 0.05)
		return (-1);
	return (speed);
}
