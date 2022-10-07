#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "include/libft.h"

void	ft_sender(int pid, char i)
{	
	int	bit;

	bit = 0;
	while (bit < 8)
	{		
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("\033[31;1mWrong Format.\n\033[32mIncorrect entry!\n\
Please enter transaction ID and message.\033[0m\n", 1);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1)
	{
		ft_putstr_fd("\033[31mHOOP handsome what are you doing. \
This is our neighborhood...\n", 2);
		return (2);
	}
	while (argv[2][i])
	{
		ft_sender(pid, argv[2][i]);
		i++;
	}
	return (0);
}