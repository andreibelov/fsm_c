/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:43:44 by abelov            #+#    #+#             */
/*   Updated: 2024/03/09 23:43:48 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSM_H
#define FSM_H

/**
 *
 * http://web.archive.org/web/20160517005245/
 * http://www.gedan.net/2008/09/08/finite-state-machine-matrix-style-c-implementation
 *
 */
/*******************************
 * typedefs
 *******************************/

typedef enum {
	STATE_0,
	STATE_1,
	STATE_2
} state;

typedef enum {
	NILACTION,
	ACTION_1,
	ACTION_2,
	ACTION_3,
	ACTION_4
} action;

typedef enum {
	NILEVENT,
	EVENT_1,
	EVENT_2
} event;

typedef struct {
	state nextState;
	action actionToDo;
}  stateElement;


stateElement stateMatrix[3][3] = {
	{
		{STATE_0,NILACTION},
		{STATE_1,ACTION_1},
		{STATE_1,ACTION_4}
		},
	{
		{STATE_1,NILACTION},
		{STATE_2,ACTION_3},
		{STATE_2,ACTION_2}
		},
	{
		{STATE_2,NILACTION},
		{STATE_0,ACTION_2},
		{STATE_1,ACTION_3}
	}
};

/***************************************
 * prototypes
 ***************************************/
action stateEval(event e);

#endif //FSM_H
