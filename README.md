# get_next_line

A function that reads from a file descriptor one line at a time. 

Built for the 42 curriculum. Each call returns the next line, however large the line is and whatever `BUFFER_SIZE` the code is compiled with. Bytes read past the end of a line are kept between calls in a `static` variable.

## Prototype

```c
char  *get_next_lien(int  fd);
```

|  Returns  |  When  |
|  ---  |  ---|
|  The next line, including its `\n` if it has one | A line was read |
| `NULL` | End of file, read error, invalid `fd` or failed allocation |

he returned string is allocated with `malloc`, so the caller must `free` it.
 
## How it works
 
1. `read_bytes` reads `BUFFER_SIZE` bytes at a time and appends them to the static stash until it finds a `\n` or reaches end of file.
2. `find_newline` copies everything up to and including the first `\n` into a new string. That string is the line returned to the caller.
3. `ft_clean` keeps what comes after the `\n` for the next call and frees the old stash. If nothing is left, it frees the stash and sets it to `NULL`.
## Usage
 
Add a `main.c` next to the source files:
 
```c
#include "get_next_line.h"
 
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
 
	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```
 
Compile and run it:
 
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
./gnl file.txt
```
 
`BUFFER_SIZE` sets how many bytes each `read` call asks for. It defaults to 42 if you leave out the flag.
 
## Limitations
 
- **One file descriptor at a time.** There is a single static stash, so alternating between descriptors mixes their data. The bonus part of the subject is not implemented.
- **Text only.** Lines are handled as C strings, so anything after a `\0` byte in the input is lost.
## Testing
 
Tested with `BUFFER_SIZE` values of 1, 2, 42 and 9999 on empty files, files with only newlines, a last line without `\n`, a single 20,000-character line and a 3,000-line file. Memory was checked with Valgrind.
