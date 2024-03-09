
#include "fsm.h"

state_t do_state_initial(instance_data_t *data)
{
	(void) data;
	ft_printf("state_initial\n");
	return (STATE_FOO);
}
state_t do_state_foo(instance_data_t *data)
{
	(void) data;
	ft_printf("state_foo\n");
	return (STATE_BAR);
}

state_t do_state_bar(instance_data_t *data)
{
	(void) data;
	ft_printf("state_bar\n");
	return (STATE_END);
}

state_t do_state_end(instance_data_t *data)
{
	(void) data;
	ft_printf("state_end\n");
	return (STATE_END);
}