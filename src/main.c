/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Main file.
*/

#include "main.h"

void start(void)
{
	char *c;

	write(1, "START_SIMULATION\n", 17);
	c = my_gnl();
	check_ops(c, 1, "START_SIMULATION");
	free (c);
	write(1, "CAR_FORWARD:1\n", 14);
	c = my_gnl();
	check_ops(c, 1, "CAR_FORWARD");
	free (c);
	usleep(10);
}

void end(void)
{
	char *c;

	write(1, "CAR_FORWARD:0\n", 14);
	c = my_gnl();
	check_ops(c, 1, "CAR_FORWARD");
	free (c);
	write(1, "STOP_SIMULATION\n", 16);
	c = my_gnl();
	check_ops(c, 10, "STOP_SIMULATION");
	free (c);
}

int main(void)
{
	char *c;
	char **tab;
	float *coord;

	start();
	while (global_track(0) == 0) {
		write(1, "GET_INFO_LIDAR\n", 15);
		c = my_gnl();
		check_ops(c, 1, "GET_INFO_LIDAR");
		tab = my_str_to_word_array(c, ':');
		check_track(tab);
		coord = gen_tab(tab);
		if (set_speed(coord) == -1)
			break;
		set_angle(coord);
		free_all(tab, coord, c);
		usleep(10);
	}
	end();
	return (0);
}
