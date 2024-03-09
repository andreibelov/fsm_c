//
// Created by andrei_belov on 3/3/24.
//

#ifndef FSM_H
#define FSM_H

#include <stddef.h>

typedef enum { STATE_INITIAL, STATE_FOO, STATE_BAR, STATE_END, NUM_STATES } state_t;

typedef struct instance_data {} instance_data_t;

typedef state_t state_func_t(instance_data_t *data);

typedef void transition_func_t(instance_data_t *data);

void do_initial_to_foo(instance_data_t *data);
void do_foo_to_bar(instance_data_t *data);
void do_bar_to_initial(instance_data_t *data);
void do_bar_to_foo(instance_data_t *data);
void do_bar_to_bar(instance_data_t *data);

static transition_func_t * const transition_table[NUM_STATES][NUM_STATES] = {
	{ NULL,              do_initial_to_foo, NULL, NULL },
	{ NULL,              NULL,              do_foo_to_bar, NULL },
	{ do_bar_to_initial, do_bar_to_foo,     do_bar_to_bar, NULL },
	{ do_bar_to_initial, do_bar_to_foo,     do_bar_to_bar, NULL }
};

state_t do_state_initial(instance_data_t *data);
state_t do_state_foo(instance_data_t *data);
state_t do_state_bar(instance_data_t *data);
state_t do_state_end(instance_data_t *data);

static state_func_t* const state_table[ NUM_STATES ] = {
	do_state_initial, do_state_foo, do_state_bar, do_state_end
};

#endif //FSM_H
