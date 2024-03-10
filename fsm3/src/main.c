/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:29:09 by abelov            #+#    #+#             */
/*   Updated: 2024/03/10 00:27:47 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "fsm.h"

action stateEval(event e)
{
	int currentState;

	//determine the State-Matrix-Element in dependany of current state and triggered event
	stateElement stateEvaluation = stateMatrix[currentState][e];

	//do the transition to the next state (set requestet next state to current state)...
	currentState = stateEvaluation.nextState;
	//... and fire the proper action
	return stateEvaluation.actionToDo;
}

void main() {

	action	actionToDo;
	event	eventOccured;
	event	someEvent;

	// this single line is the whole FSM-Call, easy as that!
	actionToDo = stateEval(eventOccured);

	if (true) {
		eventOccured = someEvent;
	}
}

