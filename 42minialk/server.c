#include <signal.h>
#include <unistd.h>
#include "include/libft.h"

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("\033[35mSend messages from Client to Server with PID.\n\
\033[32;40mServer [PID = \033[31m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\033[32m]\033[37;40;0m\n", 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
	{
		pause();
	}
}