/*! \file */

#ifndef SZDUEL_H
#define SZDUEL_H

#include "structs.h"

/** @brief Address 318280
 *
 *  Three arrays of units. The first array of 11 represents the Lancastrian
 *  units (DL, then 5 monsters, then 5 non-monsters). The next array of 11
 *  represents the Yorkist units. The purpose of the last array of 11 is
 *  unknown.
 */
extern Unit units[3][11];

/** @brief Address 318E60
 *
 *  Array of MapInfo for every square on the 7 x 7 board. The indices are given
 *  by row and column, so the square at a particular row and column is
 *  mapInfo[row][col].
 */
extern MapInfo mapInfo[7][7];

/** @brief Gets the unit given by a side and position.
 *
 *  If side is negative, pos is instead interpreted as an index into models and
 *  the type is retrieved with SzModel_GetModelType. The returned type is then
 *  converted into a standard side/pos combination as follows:
 *  - If the type is 4, side is Lancastrians if pos is <= 24 and Yorkists if
 *  pos > 24, and pos becomes old pos % 5 + 1
 *  - If the type is 5, side is pos - 30 and pos becomes 0
 *  - Any other type results in this function returning NULL.
 *
 *  After this potential conversion, a side that isn't 0, 1, or 2 or a pos that
 *  isn't between 0 and 10 inclusive is rejected and the function returns NULL.
 *  In the happy case, the function returns the address of units[side][pos].
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @return Pointer to the requested Unit
 */
Unit* SzDuel_GetCardInfo(int side, int pos);

/** @brief Gets the terrain type at a specified position.
 *
 *  The returned value should be interpreted as a member of the Field enum. If
 *  row and col do not lie between 0 and 6 inclusive, this function returns -1
 *  instead.
 *
 *  @param col Column of the desired location.
 *  @param row Row of the desired location.
 *  @return Terrain type of the corresponding square.
 */
int SzDuel_GetField(int col, int row);

/** @brief Gets the unit given by a side and position, but only if the unit is
 *  valid.
 *
 *  This function is almost the same as SzDuel_GetCardInfo, but after calling
 *  that this function checks the returned value. If the value is NULL or if the
 *  slot of the result is greater than 10, this function returns NULL, otherwise
 *  it returns the normal value. I speculate the check on slot is to make this
 *  function only return units that are currently actually on the field, and
 *  perhaps a just destroyed unit remains in the array until overwritten.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @return Pointer to the requested Unit
 */
Unit* SzDuel_GetUnit(int side, int pos);

/** @brief Return the attack of the unit specified by a side and position, which
 *  may or may not include boosts.
 *
 *  If the unit is invalid or its constInfo is NULL then this function returns
 *  -1. The function then takes constInfo->apWithFlags & 0x1FFF and will add the
 *  unit's apBoost if ignoreBoosts is false. The result is clamped to lie
 *  between 0 and 9999 inclusive and then returned.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @param ignoreBoosts Whether to add the unit's apBoost or not
 *  @return The attack of the unit
 */
int SzDuel_GetUnitAP(int side, int pos, bool ignoreBoosts);

/** @brief Return the attack of unit, which may or may not include boosts.
 *
 *  If unit or unit->constInfo is NULL then this function returns -1. The
 *  function then takes unit->constInfo->apWithFlags & 0x1FFF and will add
 *  unit->apBoost if ignoreBoosts is false. The result is clamped to lie between
 *  0 and 9999 inclusive and then returned.
 *
 *  @param unit Pointer to the unit to get the attack of
 *  @param ignoreBoosts Whether to add unit->apBoost or not
 *  @return The attack of the unit
 */
int SzDuel_GetUnitAP2(Unit* unit, bool ignoreBoosts);

/** @brief Return the attribute of the unit specified by a side and position.
 *
 *  The return value should be interpreted as a member of the Attribute enum.
 *  If there is no unit given by (side, pos), then instead -1 is returned.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @return The attribute of the specified Unit
 */
int SzDuel_GetUnitAttr(int side, int pos);

/** @brief Return the card number of the unit specified by a side and position.
 *
 *  If there is no unit given by (side, pos), then instead -1 is returned.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @return The card number of the specified Unit
 */
int SzDuel_GetUnitCardNo(int side, int pos);

/** @brief Return the defense of the unit specified by a side and position,
 *  which may or may not include boosts.
 *
 *  If the unit is invalid or its constInfo is NULL then this function returns
 *  -1. The function then takes constInfo->dpWithFlags & 0x1FFF and will add the
 *  unit's dpBoost if ignoreBoosts is false. The result is clamped to lie
 *  between 0 and 9999 inclusive and then returned.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @param ignoreBoosts Whether to add the unit's dpBoost or not
 *  @return The defense of the unit
 */
int SzDuel_GetUnitDP(int side, int pos, bool ignoreBoosts);

/** @brief Return the defense of unit, which may or may not include boosts.
 *
 *  If unit or unit->constInfo is NULL then this function returns -1. The
 *  function then takes unit->constInfo->dpWithFlags & 0x1FFF and will add
 *  unit->dpBoost if ignoreBoosts is false. The result is clamped to lie between
 *  0 and 9999 inclusive and then returned.
 *
 *  @param unit Pointer to the unit to get the defense of
 *  @param ignoreBoosts Whether to add unit->dpBoost or not
 *  @return Thedefense of the unit
 */
int SzDuel_GetUnitDP2(Unit* unit, bool ignoreBoosts);

/** @brief Return the kind of the unit specified by a side and position.
 *
 *  The return value should be interpreted as a member of the Kind enum. If
 *  there is no unit given by (side, pos), then instead -1 is returned.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @return The kind of the specified Unit
 */
int SzDuel_GetUnitKind(int side, int pos);

/** @brief Return the location of the unit specified by a side and position.
 *
 *  This function returns the position in the form of (row << 8) | col. If
 *  there is no unit given by (side, pos), then instead -1 is returned.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @return The position of the specified Unit
 */
int SzDuel_GetUnitLoc(int side, int pos);

/** @brief Return one of the status flags of the unit specified by a side and
 *  position.
 *
 *  If the unit is not valid or flag does not lie between 0 and 5 inclusive the
 *  function returns false. Otherwise the function returns whether the bit
 *  status & (0x1 << flag) is set.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @param flag The index of the flag in unit's status
 *  @return The kind of the specified Unit
 */
bool SzDuel_GetUnitStatus(int side, int pos, int flag);

/** @brief Return the summonOrder of the unit specified by a side and position.
 *
 *  If there is no unit given by (side, pos), -1 is returned.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @return The summonOrder of the specified Unit
 */
int SzDuel_GetUnitSummonOrder(int side, int pos);

#endif
