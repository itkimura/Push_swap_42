#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

/*Delete later*/
# include <stdio.h>

typedef	struct		s_dlst
{
	long			value;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;


/* validate_args.c */
int validate_args(int ac, char **av);
#endif
