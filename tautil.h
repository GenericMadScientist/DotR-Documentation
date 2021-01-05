/*! \file */

#ifndef TAUTIL_H
#define TAUTIL_H

#include "enums.h"

/** @brief Get the attack of unit if it were at a specified position.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @param col The column unit is to be on
 *  @param row The row unit is to be on
 *  @return The attack of the unit
 */
int TaUtil_GetUnitAP(int side, int pos, int col, int row);

/** @brief Get the defense of unit if it were at a specified position.
 *
 *  @param side The side (Lancastrian/Yorkist/???) to get the unit from, or
 *  negative if pos is an index into models
 *  @param pos The index into the subarray of side's units, or into models if
 *  side is negative
 *  @param col The column unit is to be on
 *  @param row The row unit is to be on
 *  @return The defense of the unit
 */
int TaUtil_GetUnitDP(int side, int pos, int col, int row);

/** @brief Fills the ownerIds of the units matching side into units.
 *
 *  This function loops over all 20 possible cards on the field and fills units
 *  with the ownerIds (side << 8 | pos) of every card whose controlling side
 *  matches side according to sideComp. The order is side, pos 1 -> 10, then
 *  !side, pos 1 -> 10.
 *
 *  The array units is not cleared in any way. There is no way for the caller to
 *  directly get the number of elements inserted into units. In theory up to 20
 *  units could be filled in so the array units should have enough capacity for
 *  20 unsigned shorts.
 *
 *  @param side The side to get the units of
 *  @param sideComp The way to compare the cards' controlling sides and side
 *  @param units The output buffer
 */
void TaUtil_GetUnitLst(int side, SideComp sideComp, unsigned short* units);

#endif
