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

/** @brief Gets the stat bonuses from the two leaders.
 *
 *  This gets the change in stats due to Increased Strength for Same Type
 *  Friendlies and Weaken Specific Enemy Type. SzDuel_GetUnitLevel is used to
 *  calculate the changes, rather than the data embedded in LeaderAbilities.
 *
 *  @param unit The unit to be strengthened and/or weakened
 *  @param col The column unit is to be on
 *  @param row The row unit is to be on
 *  @return The stat bonuses the leaders apply to unit
 */
int Ta_GetLDParamOfs2(Unit* unit, int col, int row);

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

/** @brief Returns if side's leader would power down opposing cards with the
 *  given kind, if said leader had Weaken Specific Enemy Type.
 *
 *  Side's leader's kind is what determines the kinds it powers down. The
 *  correspondence is given below, in the form Leader kind -> powered down
 *  kinds.
 *
 *  Spellcaster -> Fiend
 *
 *  Zombie -> Warrior
 *
 *  Warrior -> Dragon and Spellcaster
 *
 *  Beast -> Fish
 *
 *  Winged Beast -> Insect and Fish
 *
 *  Fiend -> Spellcaster
 *
 *  Insect -> Sea Serpent
 *
 *  Reptile -> Beast and Winged Beast
 *
 *  Fish -> Thunder
 *
 *  Thunder -> Zombie and Machine
 *
 *  Aqua -> Machine and Pyro
 *
 *  Pyro -> Beast-Warrior
 *
 *  others -> None
 *
 *  @param side Side of leader
 *  @param objKind Kind of opposing monster
 *  @return Whether side's leader would power down objKind cards
 */
bool Ta_IsLD_PDownObj(int side, Kind objKind);

/** @brief Gets if side's leader has the specified type of ability active.
 *
 *  This function takes into account the effect of Moisture Creature. If the
 *  opponent has Moisture Creature's Nature Effect active, this function returns
 *  false. Otherwise it returns the result of SzDuel_GetUnitLeaderAbility.
 *
 *  @param ability Type of leader ability to check for
 *  @param side The side (Lancastrian/Yorkist/???) to check the leader of
 *  @return Whether the side's leader has the specified ability active
 */
bool Ta_IsLDAbl(LeaderAbility ability, int side);

/** @brief Gets if a square is in range of a side's leader.
 *
 *  This function checks a 5 x 5 square around side's leader if it has Extended
 *  Support Range, or a 3 x 3 square otherwise.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to check the leader of
 *  @param col The column of the position to check
 *  @param row The row of the position to check
 *  @return Whether the side's leader has the specified ability active
 */
bool Ta_IsLDRange(int side, int col, int row);

/** @brief Gets if a side's leader has the given kind and ability that covers
 *  loc.
 *
 *  This function returns true only if side's leader has the given kind, the
 *  given ability, and if loc is within the range of side's leader.
 *
 *  @param loc The location of the position to check, of the form
 *  (row << 8) | col
 *  @param side The side (Lancastrian/Yorkist/???) to check the leader of
 *  @param kind The desired kind
 *  @param ability The ability to check
 *  @return Whether the side's leader has the right kind and ability active at
 *  loc
 */
bool Ta_IsLDRangeAvilityFromLoc(
    int loc, int side, Kind kind, LeaderAbility ability);

/** @brief Checks if one point is inside a specified square.
 *
 *  The centre of the square is given by (srcCol, srcRow) and is given by the
 *  points (p_col, p_row) such that |p_col - srcCol| <= range / 2 and
 *  |p_row - srcRow| <= range / 2.
 *
 *  @param srcCol The column of the square's centre
 *  @param srcRow The row of the square's centre
 *  @param col The column of the point to check
 *  @param row The row of the point to checl
 *  @param range Roughly speaking, the length of the square's sides
 *  @return Whether (col, row) is inside the specified square
 */
bool Ta_IsSquareRange(int srcCol, int srcRow, int col, int row, int range);

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
