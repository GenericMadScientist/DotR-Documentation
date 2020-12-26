/*! \file */

#ifndef TA_H
#define TA_H

#include "enums.h"
#include "structs.h"

/** @brief Gets the side controlling a unit specified by a side and position.
 *
 *  If SzDuel_GetUnitStatus(unit, pos, 1) returns false, side is returned.
 *  Otherwise !side is returned.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @return The side controlling the specified unit
 */
int Ta_GetCurrentSide(int side, int pos);

/** @brief Gets the side controlling a unit.
 *
 *  If unit is NULL, the function returns -1. Otherwise it returns the side
 *  controlling unit, taking into account if the unit is currently controlled
 *  by cards like Brain Control.
 *
 *  @param unit The unit to check
 *  @return The side controlling unit
 */
int Ta_IsUnitControl2(Unit* unit);

/** @brief Return if two sides match according to compMode.
 *
 *  If compMode is ALWAYS_MATCH, the result is true.
 *  If compMode is MATCH_IF_EQUAL, the result is sideA == sideB.
 *  If compMode is MATCH_IF_NOT_EQUAL, the result is sideA == !sideB.
 *  If compMode is NEVER_MATCH, the result is false.
 *  If compMode is anything else, the result is false.
 *
 *  @param sideA The first side to compare
 *  @param sideB The second side to compare
 *  @param compMode The way to compare the two sides
 *  @return Whether the two sides match
 */
bool Ta_SideMatch(int sideA, int sideB, SideComp compMode);

#endif
