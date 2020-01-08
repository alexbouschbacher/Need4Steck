/*
** EPITECH PROJECT, 2018
** my_str_word_to_array
** File description:
** segment a string
*/

#include "main.h"

void calloc_str(char **tab, int x, int count_ltr)
{
	tab[x] = calloc (1, count_ltr + 1);
	if (tab[x] == NULL) {
		fprintf(stderr, "Malloc failed.\n");
		exit (84);
	}
}

static char **tabl_malloc (int words, char const *str, char sep)
{
	int count_ltr = 0;
	int x = 0;
	char **tab;

	if ((tab = malloc (sizeof (char *) * (words + 1)))== NULL) {
		fprintf(stderr, "Malloc failed.\n");
		exit (84);
	}
	for (int i = 0 ; str[i]; i++) {
		if (str[i] == sep) {
			count_ltr = 0;
		} else if (str[i + 1] == '\0' || str[i + 1] == sep) {
			count_ltr += 2;
			calloc_str(tab, x, count_ltr);
			x += 1;
			count_ltr = 0;
		} else
			count_ltr += 1;
	}
	return (tab);
}

static void end_word(char c, char **tab, int *coord, char sep)
{
	if (c == '\0') {
		tab[coord[0]][coord[1]] = '\0';
		coord[0] = coord[0] + 1;
	} else if (c == sep) {
		tab[coord[0]][coord[1]] = '\0';
		coord[0] = coord[0] + 1;
		coord[1] = 0;
	}
}

static void implant (char const *str, char **tab, char sep)
{
	int x = 0;
	int y = 0;
	int *coord = malloc (sizeof (int) * 2);

	for (int i = 0 ; str[i]; i++) {
		if (str[i] != sep) {
			tab[x][y] = str[i];
			y += 1;
			coord[0] = x;
			coord[1] = y;
			end_word(str[i + 1], tab, coord, sep);
			x = coord[0];
			y = coord[1];
		}
	}
	tab[x] = NULL;
	free (coord);
}

char **my_str_to_word_array(char *str, char sep)
{
	int words = 0;
	int now;
	int next;
	char **tab;

	for (int i = 0 ; str[i]; i++) {
		now = (str[i] == sep) ? 1 : 0;
		next = (str[i + 1] == sep || str[i + 1] == '\0') ? 1 : 0;
		if (next != now && now == 0)
			words += 1;
	}
	tab = tabl_malloc (words, str, sep);
	implant (str, tab, sep);
	return (tab);
}
