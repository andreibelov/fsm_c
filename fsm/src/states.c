#include "fsm.h"

int entry_state(void)
{
	ft_printf("entry_state\n");
	return (ok);
}

int foo_state(void)
{
	ft_printf("foo_state\n");
	return (ok);
}

int bar_state(void)
{
	ft_printf("bar_state\n");
	return (ok);
}

int exit_state(void)
{
	ft_printf("exit_state\n");
	return (ok);
}