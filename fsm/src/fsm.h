//
// Created by andrei_belov on 3/3/24.
//

#ifndef FSM_H
#define FSM_H

#import "libft.h"

#define EXIT_STATE end
#define ENTRY_STATE entry

int entry_state(void);
int foo_state(void);
int bar_state(void);
int exit_state(void);

enum state_codes { entry, foo, bar, end };
enum ret_codes { ok, fail, repeat };

typedef struct transition {
	enum state_codes src_state;
	enum ret_codes   ret_code;
	enum state_codes dst_state;
} transition_t;

/* transitions from end state aren't needed */
static struct transition state_transitions[] = {
	{entry, ok,     foo},
	{entry, fail,   end},
	{foo,   ok,     bar},
	{foo,   fail,   end},
	{foo,   repeat, foo},
	{bar,   ok,     end},
	{bar,   fail,   end},
	{bar,   repeat, foo}
};

#endif //FSM_H
