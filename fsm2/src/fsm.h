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
 * http://web.archive.org/web/20150905150146/
 * http://contrarymotion.net/2008/02/12/some-code-snippets-for-a-simple-c-state-machine/
 */
typedef enum {
	STATE_0,
	STATE_1,
	STATE_2
} state;

#define STATE_ENTRY_ACTION if ( currentState != previousState ) {
#define STATE_TRANSITION_TEST previousState = currentState; } if ( nextState == currentState ) {
#define STATE_TRANSITION_TEST_EXCLUSIVE } else if ( nextState == currentState ) {
#define STATE_EXIT_ACTION } if ( nextState != currentState ) {
#define STATE_EXIT_ACTION_EXCLUSIVE } else if ( nextState != currentState ) {
#define STATE_END currentState = nextState; } break;

int doColor(void);
int checkUserInput(void);
int fadeColor(void);

#endif //FSM_H
