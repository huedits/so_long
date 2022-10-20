#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

void	generate_map(void);

int	main(void)
{
	int	id;
	int	fd;
	char	*buf;

	id = fork();
	if (id == 0)
		generate_map();
	else
	{
		wait(NULL);
		fd = open("map", O_RDONLY);
		if (fd == -1)
		{
			printf("Erro ao abrir arquivo.\n");
			return (0);
		}
		while (read(fd, &buf, 1))
			write(1, &buf, 1);
		close(fd);
	}
}

void	generate_map(void)
{
	int	pid;

	if (access("mapgen", X_OK) == 0)
		execl("mapgen", "mapgen", NULL);
	else
	{
		pid = fork();
		if (pid == 0)
			execlp("make", "make", "mapgen", NULL);
		else
		{
			wait(NULL);
			execl("mapgen", "mapgen", NULL);
		}
	}
}
