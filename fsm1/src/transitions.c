#include "fsm.h"

void	do_initial_to_foo( instance_data_t *data )
{
	ft_printf("transitioning from initial_to_foo\n");
	(void) data;
}

void	do_foo_to_bar( instance_data_t *data )
{
	ft_printf("transitioning from foo_to_bar\n");

	(void) data;
}

void	do_bar_to_initial( instance_data_t *data )
{
	ft_printf("transitioning from bar_to_initial\n");
	(void) data;
}

void	do_bar_to_foo( instance_data_t *data )
{
	ft_printf("transitioning from bar_to_foo\n");
	(void) data;
}

void	do_bar_to_bar( instance_data_t *data )
{
	ft_printf("transitioning from bar_to_bar\n");
	(void) data;
}

void	do_bar_to_end( instance_data_t *data )
{
	ft_printf("transitioning from bar_to_end\n");
	(void) data;
}

void	do_end_to_end( instance_data_t *data )
{
	ft_printf("transitioning from end_to_end\n");
	(void) data;
}
