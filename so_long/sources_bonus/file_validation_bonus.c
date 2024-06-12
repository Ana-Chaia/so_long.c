/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:42:32 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/16 14:25:38 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	is_extension_valid(char *argv[])
{
	const char	*extension;

	extension = ".ber";
	if (strcmp(argv[1], extension) == 0)
	{
		ft_printf("invalid format of extension \n");
		return (0);
	}
	else if (strcmp (argv[1] + ft_strlen (argv[1]) - ft_strlen(extension),
			extension) == 0)
		return (1);
	else
	{
		ft_printf("file does not end with '.ber'\n");
		return (0);
	}
}

char	*read_file(int file_descriptor)
{
	char		str[101];
	ssize_t		result;
	char		*third;
	static char	*text;

	result = read (file_descriptor, str, 100);
	if (result < 0)
		return (NULL);
	str[result] = '\0';
	while (result != 0)
	{
		third = text;
		text = ft_strjoin(text, str);
		free (third);
		if (text == NULL)
			return (NULL);
		result = read (file_descriptor, str, 100);
		if (result < 0)
		{
			free(text);
			return (NULL);
		}
		str[result] = '\0';
	}
	return (text);
}

char	*open_file(char *filename)
{
	int		file_descriptor;
	char	*text;

	file_descriptor = open (filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		ft_printf("can not open file");
		return (0);
	}
	else
	{
		text = read_file(file_descriptor);
		if (text == NULL)
			return (NULL);
		else
			return (text);
	}
}

int	is_there_space(char*text)
{
	size_t	index;

	index = 0;
	text = ft_strchr(text + index, '1');
	if (text == NULL)
	{
		ft_printf("ERROR\n - map is not valid\n");
		return (0);
	}
	while (text[index] != '\0')
	{
		if (text[index] == '\n' && text[index + 1] == '\n')
		{
			if (ft_strchr_inverse(text + index, '\n') == NULL)
				return (1);
			else
			{
				ft_printf("ERROR\n - map is not valid\n");
				return (0);
			}
		}
		index++;
	}
	return (1);
}

int	ft_file_validation_bonus(char **argv, t_maps *mapcontent)
{
	int		result;

	if (is_extension_valid (argv) == 0)
		return (0);
	mapcontent->filecontent = open_file(argv[1]);
	if (mapcontent->filecontent == NULL)
	{
		ft_printf("ERROR\n - empty map\n");
		return (0);
	}
	result = is_there_space (mapcontent->filecontent);
	if (result == 0)
	{
		free(mapcontent->filecontent);
		return (0);
	}
	else
		return (1);
}
