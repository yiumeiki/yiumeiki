/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entries.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myiu <myiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:18:41 by myiu              #+#    #+#             */
/*   Updated: 2025/02/20 11:07:12 by myiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

t_entry	*copy_dirent(struct dirent *dirent)
// Copies the relevant data about a directory entry
// and returns it in a t_entry struct
{
	t_entry	*entry;

	entry = ft_calloc(1, sizeof(*entry));
	ft_strlcpy(entry->d_name, dirent->d_name, NAME_MAX);
	entry->d_type = dirent->d_type;
	return (entry);
}

t_list	*get_entries(t_prog *term)
// Returns a list of the t_entry structs, containing data
// about the entries in the current working directory,
{
	struct dirent	*dirent;
	DIR				*dir;
	t_list			*entries;
	t_entry			*entry;

	entries = NULL;
	dir = opendir(term->cwd);
	dirent = readdir(dir);
	while (dirent != NULL)
	{
		if (ft_strncmp(dirent->d_name, ".", 2)
			&& ft_strncmp(dirent->d_name, "..", 3))
		{
			entry = copy_dirent(dirent);
			ft_lstadd_front(&entries, ft_lstnew(entry));
		}
		dirent = readdir(dir);
	}
	closedir(dir);
	return (entries);
}

char	*get_dname(t_list *node)
// Returns the name of an entry from a list node containing its t_entry struct
{
	return (((t_entry *)node->content)->d_name);
}

unsigned char	get_dtype(t_list *node)
// Returns the type of an entry from a list node containing its t_entry struct
{
	return (((t_entry *)node->content)->d_type);
}

void	print_entries(t_list *entries)
// Prints a list of t_entry structs
{
	t_list	*current;

	current = entries;
	while (current != NULL)
	{
		ft_printf("\e[1;3%dm%s\e[m\t", get_dtype(current), get_dname(current));
		current = current->next;
	}
	ft_printf("\n");
}
