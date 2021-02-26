/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:16:25 by lpascrea          #+#    #+#             */
/*   Updated: 2021/02/26 17:57:46 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_error(int nbr)
{
	if (nbr == 0)
		write(2, "Error\nMissing '.cub' file\n", 26);
	if (nbr == 1)
		write(2, "Error\nInvalide file, we want .cub\n", 34);
	if (nbr == 2)
		write(2, "Error\nYour choosen file doesn't exist\n", 38);
	if (nbr == 3)
	{
		write(2, "Error\nYour map is missing starter coordinates\n", 46);
		write(2, "Or she's not at end\n", 20);
	}
	if (nbr == 4)
		write(2, "Error\nProblem with memory allocation\n", 37);
	if (nbr == 5)
		write(2, "Error\nYour choosen file is empty\n", 33);
	if (nbr == 6)
		write(2, "Error\nargv[2] must be '--save'\n", 31);
	if (nbr == 7)
		write(2, "Error\nProblem while initialize textures\n", 40);
	if (nbr == 8)
		write(2, "Error\nYour file texture isn't correct\n", 38);
	if (nbr == 9)
		write(2, "Error\nProblem while saving .bmp\n", 32);
	return (0);
}

int		ft_error_file(int nbr)
{
	if (nbr == 0)
		write(2, "Error\nYour screen resolution cannot be 0\n", 41);
	if (nbr == 1)
		write(2, "Error\nline in double in .cub file\n", 34);
	if (nbr == 2)
		write(2, "Error\nBad informations in your .cub file\n", 41);
	return (0);
}

int		ft_error_parsing(int nbr)
{
	if (nbr == 0)
		write(2, "Error\nProblem with line NO\n", 27);
	if (nbr == 1)
		write(2, "Error\nProblem with line SO\n", 27);
	if (nbr == 2)
		write(2, "Error\nProblem with line WE\n", 27);
	if (nbr == 3)
		write(2, "Error\nProblem with line EA\n", 27);
	if (nbr == 4)
		write(2, "Error\nProblem with line R\n", 26);
	if (nbr == 5)
		write(2, "Error\nProblem with line C\n", 26);
	if (nbr == 6)
		write(2, "Error\nProblem with line F\n", 26);
	if (nbr == 7)
		write(2, "Error\nProblem with line S\n", 26);
	if (nbr == 8)
		write(2, "Error\nMap isn't closed\n", 23);
	if (nbr == 9)
		write(2, "Error\nFile is missing needed informations\n", 42);
	if (nbr == 10)
		write(2, "Error\nMap rules not respected\n", 30);
	return (0);
}
