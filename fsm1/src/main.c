/*
 * https://stackoverflow.com/questions/133214/is-there-a-typical-state-machine-implementation-pattern
 */

#include <sysexits.h>
#include <stdlib.h>
#include "fsm.h"



//state_t run_state( state_t cur_state, instance_data_t *data ) {
//	return state_table[ cur_state ]( data );
//};


state_t run_state( state_t cur_state, instance_data_t *data )
{
	state_func_t	*state_fun;
	transition_func_t *transition;

	state_fun = state_table[cur_state];
	state_t new_state = state_fun(data);
	transition = transition_table[ cur_state ][ new_state ];
	if (transition)
		transition(data);
	return (new_state);
}

int main(void)
{
	state_t cur_state;
	state_t next_state;
	instance_data_t data;

	next_state = STATE_INITIAL;
	cur_state = next_state;
	while (STATE_END != cur_state)
	{
		next_state = run_state(cur_state, &data);
		// do other program logic, run other state machines, etc
		cur_state = next_state;
	}
}
