/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Main file.
*/

#include "main.h"

float *gen_tab(char **tab)
{
	float *pos = malloc (sizeof (float) * 32);

	for (int i = 3; i != 35; i++)
		pos[i - 3] = atof(tab[i]);
	return (pos);
}

float gen_moy(float *tab, int a, int b)
{
	float moy = 0;
	int dif = b - a + 1;

	for (int i = 0; i < dif; i++)
		moy += tab[a + i];
	moy = (moy * 1.0) / dif;
	return (moy);
}

char *my_gnl(void)
{
	char *c = NULL;
	size_t size;
	int len;

	getline(&c, &size, stdin);
	len = strlen(c);
	c[len - 1] = '\0';
	return (c);
}
