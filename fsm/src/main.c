/*
 * https://stackoverflow.com/questions/1371460/state-machines-tutorials
 */

#include <stdlib.h>
#include <stdbool.h>

#include "fsm.h"

/* array and enum below must be in sync! */
int (* state[])(void) = {
	entry_state,
	foo_state,
	bar_state,
	exit_state
};

enum state_codes lookup_transitions(enum state_codes cur_state, enum ret_codes rc)
{
	size_t	i;
	transition_t transition;
	enum state_codes dst_state;

	i = 0;
	dst_state = cur_state;
	while(i < sizeof(state_transitions))
	{
		transition = state_transitions[i++];
		if (transition.src_state == cur_state && transition.ret_code == rc)
			break;
	}
	dst_state = transition.dst_state;
	return (dst_state);
}

int main(int argc, char *argv[])
{
	enum state_codes cur_state;
	enum state_codes next_state;
	enum ret_codes rc;
	int (* state_fun)(void);

	next_state = ENTRY_STATE;
//	cur_state = next_state;
	while (EXIT_STATE != cur_state)
	{
		cur_state = next_state;
		state_fun = state[cur_state];
		rc = state_fun();
		next_state = lookup_transitions(cur_state, rc);
	}

	return (EXIT_SUCCESS);
}