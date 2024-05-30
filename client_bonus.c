/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:54:22 by oadewumi          #+#    #+#             */
/*   Updated: 2024/05/30 21:08:49 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

static void	client_err_msg(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

static void	validate_argument(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]))
			client_err_msg("Invalid Pid");
		i++;
	}
}

static void	client_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_putendl_fd("message received by server", 1);
}

//This helper function to the main function helps to encrypt
//each character of the string passed to it and sends this to 
//the server. There are 2 conditions in the while loop that lets
//the server know which bit its receiving.
//the if condition used cn also be written as this:
//if ((temp_c >> i) % 2 == 0)
//Although, using purely bit wise operation is more intuitive to read.
static void	ft_send_bits(int pid, unsigned char c)
{
	int				i;
	unsigned char	temp_c;

	temp_c = c;
	i = 8;
	while (i > 0)
	{
		i--;
		if ((temp_c >> i) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				client_err_msg("kill function failed (SIGUSR2)\n");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				client_err_msg("kill function failed (SIGUSR1)\n");
		}
		usleep(150);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	int					i;
	char				*str_sent;
	struct sigaction	sa;

	i = 0;
	sa.sa_handler = client_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		client_err_msg("sigaction failed\n");
	if (argc != 3)
		client_err_msg("Too few or too many arguments mate");
	else
	{
		validate_argument (&argv[1][0]);
		pid = ft_atoi(argv[1]);
		str_sent = argv[2];
		while (str_sent[i])
		{
			ft_send_bits(pid, (unsigned char)str_sent[i]);
			i++;
		}
		ft_send_bits(pid, '\0');
	}
	return (0);
}
