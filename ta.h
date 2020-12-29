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

/** @brief Return an effect of the unit specified by a side and position.
 *
 *  If the unit is invalid or if effInd does not lie between 0 and 4 inclusive
 *  then NULL is returned. Otherwise cardEffects is interpreted as an array of
 *  5 Effects and a pointer to the effInd'th element is returned. effInd
 *  corresponds to the following types of effect:
 *  0 - Attack
 *  1 - Movement
 *  2 - Nature Effect
 *  3 - Flip
 *  4 - Destruction
 *
 *  The only difference between this and SzDuel_GetUnitEffect is if the effect
 *  is not valid (because it is all 0xFFs), this function will return NULL.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @param effInd The index of the effect type
 *  @return The corresponding effect of the unit
 */
Effect* Ta_GetUnitEffect(int side, int pos, int effInd);

/** @brief Gets the side controlling a unit specified by a side and position.
 *
 *  This function is completely identical with Ta_GetCurrentSide. In fact, it's
 *  a jump to Ta_GetCurrentSide.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @return The side controlling the specified unit
 */
int Ta_IsUnitControl(int side, int pos);

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

/** @brief Gets the nth unit on the field with a given nature effect in correct
 *  position.
 *
 *  The units counted are those in face-up defense position with the nature
 *  effect of type effect. n counts up from 0. The order the units are scanned
 *  in are Lancastrian 1 -> 11, then Yorkist 1 -> 11.
 *
 *  @param effect The type of nature effect to look for
 *  @param n The count of unit to search for
 *  @return (side << 8) | pos of the matching unit, or -1 if there is none
 */
int Ta_SearchUncTypeNaturalEffectUser(int effect, int n);

/** @brief Gets the number of units with the given nature effect and are in
 *  face-up defense position.
 *
 *  The units counted are those in face-up defense position with the nature
 *  effect of type effect.
 *
 *  @param effect The type of nature effect to look for
 *  @return The number of matching units
 */
int Ta_SearchUncTypeNaturalEffectUserNum(int effect);

/** @brief Gets the number of units with the given nature effect that are in
 *  face-up defense position and are currently controlled by side.
 *
 *  The units counted are those in face-up defense position with the nature
 *  effect of type effect.
 *
 *  @param effect The type of nature effect to look for
 *  @param side The side of units to look over
 *  @return The number of matching units
 */
int Ta_SearchUncTypeNaturalEffectUserNumWithSide(int effect, int side);

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
