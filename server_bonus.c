/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:08:23 by oadewumi          #+#    #+#             */
/*   Updated: 2024/05/31 21:28:46 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

static void	server_err_msg(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

static char	*concatenate_str(char *str, char c)
{
	int				i;
	char			*result;
	static char		temp[2];

	i = 0;
	temp[i] = c;
	i++;
	temp[i] = '\0';
	result = ft_strjoin(str, temp);
	free (str);
	return (result);
}

void	print_and_destroy(char **str)
{
	ft_printf("%s\n", *str);
	free(*str);
	*str = NULL;
}

//Static variables (both local and global) are initialized 
//to 0 (for arithmetic types) or NULL (for pointers) if not explicitly 
//initialized.
//the pointer to the variable "context" was made a void since its unused.
static void	handler(int signum, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	c;
	static char				*str;

	(void)context;
	if (signum == SIGUSR2)
		c = ((c << 1) | 1);
	else if (signum == SIGUSR1)
		c = (c << 1);
	i++;
	if (i == 8)
	{
		if (!str)
			str = ft_strdup("");
		str = concatenate_str(str, c);
		i = 0;
		if (c == '\0')
		{
			print_and_destroy(&str);
			kill(info->si_pid, SIGUSR1);
		}
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Process ID (PID): %d\n", getpid());
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			server_err_msg("sigaction failed (SIGUSR1)");
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			server_err_msg("sigaction failed (SIGUSR2)");
		pause();
	}
}
