/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:29:09 by abelov            #+#    #+#             */
/*   Updated: 2024/03/09 23:29:11 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "fsm.h"

void main() {
	int state;
	int currentState;
	int previousState;
	int nextState;
	while (currentState != STATE_2) {
		switch (state) {
			case STATE_0:
				STATE_ENTRY_ACTION
					doColor();
				STATE_TRANSITION_TEST
					checkUserInput();
				STATE_EXIT_ACTION
					fadeColor();
				STATE_END
		}
	}
}

int doColor(void)
{
	return (0);
}

int checkUserInput(void)
{
	return (0);
}
int fadeColor(void)
{
	return (0);
}