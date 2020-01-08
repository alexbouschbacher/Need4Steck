/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Main file.
*/

#include "main.h"

void free_tab(char **tab)
{
	for (int i = 0; tab[i]; i++)
		free (tab[i]);
	free (tab);
}

void free_all(char **tab, float *tab2, char *str)
{
	if (tab != NULL)
		free_tab(tab);
	if (tab2 != NULL)
		free (tab2);
	if (str != NULL)
	 	free (str);
}

int global_track(int add)
{
	static int a = 0;

	a += add;
	return (a);
}

void check_track(char **tab)
{
	int i = 0;

	for (; tab[i]; i++);
	i-=2;
	if (!strcmp(tab[i], "Track Cleared"))
		global_track(1);
}

void check_ops(char *c, int ok, char *error)
{
	char **tab = my_str_to_word_array(c, ':');

	if (atoi(tab[0]) != ok) {
		fprintf(stderr, "%s\n", tab[2]);
		free_tab(tab);
		free(c);
		exit (84);
	} else if (!strcmp("KO", tab[1])) {
		fprintf(stderr, "%s failed\n", error);
		free_tab(tab);
		free(c);
		exit (84);
	}
	free_tab(tab);
}
