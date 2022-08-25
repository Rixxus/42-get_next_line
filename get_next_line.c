/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:25:58 by rmount            #+#    #+#             */
/*   Updated: 2022/08/25 15:26:18 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_leftovers(char *line)
{

}


/* This function ...
   bytes_read is a counter for the number of bytes we read
   floor_tile is temp storage - like a sim. or me.

	1. bytes_read is initialised to 1 to ensure the following while loop
	is entered.

	2. while loop remains true as long as bytes_read does not equal zero.
	if bytes_read becomes equal to zero, it means we have reached the end of
	the file or ???? TO DO

	3. bytes_read is intialised with the return of the read function passing
	fd, buffer and BUFFER_SIZE which returns an integer of the number of bytes
	it was able to read. The read function takes the file descriptor, the buffer 
	pointer and BUFFER_SIZE and writes BUFFER_SIZE number of bytes from the 
	file matching the fd to the the buffer pointer.  

	4. if bytes_read equals -1 it means that there was an error calling the
	read function and read_up_to_buffer will return NULL to get_next_line.

	5. if bytes_read equals zero, it means we have reached the end of the
	file we are reading, in which case we break out of the loop and pick up
	at the next line of code outside the else if.

   6. buffer at index bytes_read is set to null as we need to assign 
   it a null terminating character to show where the line ends.

   7. 

*/

static char *read_up_to_buffer(int fd, char *buffer, char *backlog)
{
	int bytes_read;
	char *floor_tile;

	bytes_read = 1;
	while (bytes_read !=0) {
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1) {
			return (NULL);
		} 
		else if (bytes_read == 0) {
			break;
		}
		buffer[bytes_read] = '\0';
		if (!backlog) {
			backlog = ft_strdup("");
		}
	}
}

/* This function takes in the file descriptor of a file to read from.
   Three variables are created inside the function - a character pointer 'line',
   a character pointer 'buffer' and a static character pointer 'backlog'.
   
   *line will 
   *buffer will be initialised to the size required to hold the BUFFER_SIZE
   *backlog is a static variable - this means that it remembers its value 
   throughout the entire lifetime of the program and not just in its 
   particular scope.

   BUFFER_SIZE is passed in when the program is compiled.

   1. if statement checks whether the value of fd is less than zero - not a valid
   file - or the BUFFER_SIZE passed in is less than or equal to zero - not a 
   valid length. If either of these conditions are true, get_next_line returns
   NULL and ends.

   2. buffer is initialised with memory allocated the size of the
   BUFFER_SIZE +1 for the null-terminating character.

   3. if !buffer is true, it means the malloc has failed, so get_next_line 
   returns null and ends.

   4. line is initialised with a call to the function 'read_up_to_buffer' - 
   which is passed the file descripter, buffer and backlog variables.
   NOTE: while it looks like the line, buffer and backlog variables are
   being passed by value rather than reference

   5. free(buffer) is called to free the memory that was malloced to the 
   buffer variable.

   6. buffer is set to null for the next time get_next_line is called.

   7. if !line is true, read_up_to_buffer has either failed or the end
   of the file has been reached, in which case get_next_line returns 
   NULL and ends.

   8. backlog is initialised with the return from the function 
   get_leftovers, which is passed the line variable when called.
*/

char *get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char *backlog;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
	{
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (NULL);
	}
	line = read_up_to_buffer(fd, buffer, backlog);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		return (NULL);
	}
	backlog = get_leftovers(line);
	return (line);
}