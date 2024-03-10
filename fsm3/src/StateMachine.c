/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StateMachine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:52:27 by abelov            #+#    #+#             */
/*   Updated: 2024/03/10 12:52:30 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * http://web.archive.org/web/20080925090448/
 * http://www.techranch.com:80/Files/StateMachine.c
 */
#include <stdbool.h>

// State machine helper macros.
#define STATE_ENTRY_ACTION                if (CurrentState != PreviousState) { PreviousState = CurrentState;
#define STATE_TRANSITION_TEST             } if (NextState == CurrentState) {
#define STATE_TRANSITION_TEST_EXCLUSIVE   } else if (NextState == CurrentState) {
#define STATE_EXIT_ACTION                 } if (NextState != CurrentState) { CurrentState = NextState;
#define STATE_EXIT_ACTION_EXCLUSIVE       } else if (NextState != CurrentState) { CurrentState = NextState;
#define STATE_END                         } break;

#define ON true
#define OFF false

// Create an enumeration for consistent designation of states
typedef enum
{
	STATE_POWER_UP,
	STATE_1,
	STATE_2,
	DEPLOYING,
	STATE_3,
	STATE_4,
	STATE_RESERVED
} MachineState_t;

int ClearButtonPressed(void);
int NextButtonPressed(void);
int ResetSwitchPressed(void);

// ----------------------------------------------------------------------------
// Periodic processing of the state machine.
// Check for state transitions according to the current state.
// ----------------------------------------------------------------------------
void ProcessStateTick(void)
{
	static MachineState_t PreviousState = STATE_POWER_UP;
	static MachineState_t CurrentState  = STATE_POWER_UP;
	static MachineState_t NextState     = STATE_POWER_UP;

	static int CountdownTimer;

	bool RedLed;
	bool BlueLed;
	bool GreenLed;
	bool YellowLed;
	
	// Check for global state transition requests.
	if (ResetSwitchPressed())
		NextState = STATE_1;
	// Process according to current state.
	switch (CurrentState)
	{
		// Always get here once and only once.
		// Do some initialization and set up for first state.
		case STATE_POWER_UP:
			CurrentState = STATE_1;
			NextState    = STATE_1;
			break;

		case STATE_1:
			// Do entry `actions` if first time in.
			if (CurrentState != PreviousState)
			{
				// Remember that we were here.
				PreviousState = CurrentState;
				// Perform entry actions here.
				CountdownTimer = 10;
				RedLed = ON;
			}
			// Check for conditions of state transition.
			else if (NextState == CurrentState)
			{
				if (--CountdownTimer == 0)
				{
					NextState = STATE_2;
				}
			}
			// Do exit actions if leaving this state.
			else if (NextState != CurrentState)
			{
				// Set up for next state.
				CurrentState = NextState;

				// Perform exit actions here.
				RedLed = OFF;
			}
			break;

		case DEPLOYING:
			if (CurrentState != PreviousState)
			{
				PreviousState = CurrentState;
				CountdownTimer = 15;
				YellowLed = ON;
			}
			else if (NextState == CurrentState)
			{
				if ((--CountdownTimer == 0) ||
					 NextButtonPressed())
				{
					NextState = STATE_3;
				}
				else if (ClearButtonPressed())
				{
					NextState = STATE_1;
				}
			}
			else if (NextState != CurrentState)
			{
				CurrentState = NextState;
				YellowLed = OFF;
			}
			break;

		case STATE_3:

			STATE_ENTRY_ACTION
				GreenLed = ON;
			STATE_TRANSITION_TEST
				if (NextButtonPressed())
					NextState = STATE_4;
				else if (ClearButtonPressed())
					NextState = STATE_1;
			STATE_EXIT_ACTION
				GreenLed = OFF;
			STATE_END

		case STATE_4:
			STATE_ENTRY_ACTION
				CountdownTimer = 5;
				BlueLed = ON;
			STATE_TRANSITION_TEST
				if (--CountdownTimer == 0)
					NextState = STATE_1;
			STATE_EXIT_ACTION
				BlueLed = OFF;
			STATE_END
	}
}

int ClearButtonPressed(void)
{
	bool clear_button;

	if(clear_button)
		return (false);
	else
		return (true);
}


int NextButtonPressed(void)
{
	bool next_button;

	if(next_button)
		return (false);
	else
		return (true);
}


int ResetSwitchPressed(void)
{
	bool reset_switch;

	if(reset_switch)
		return (false);
	else
		return (true);
}
