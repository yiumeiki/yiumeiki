# get_next_line
Developed a function to read a file descriptor line by line with optimized buffer management. Implemented a dynamic allocation strategy to handle variable-length lines efficiently while minimizing memory leaks. The bonus part extended functionality to support multiple file descriptors simultaneously.

## How to run
add int main() to call the main function:
	
	int main(int argc, char **argv)
	{
	    int     fd;
	    char    *line;
	    int     line_count = 0;

	    fd = open(argv[1], O_RDONLY);
	    if (fd == -1)
	    {
	        perror("open");
	        return 1;
	    }

	    while ((line = get_next_line(fd)) != NULL)
	    {
	        printf("Line %d: %s", ++line_count, line);
	        free(line);
	    }

	    close(fd);
	    return 0;
	}

for mandatory part:

	cc -o get_next_line get_next_line.c get_next_line_utils.c  
	./get_next_line "file_name"

for bonus part:

	cc -o get_next_line get_next_line_bonus.c get_next_line_utils_bonus.c  
	./get_next_line "file_name" "file_name2"
