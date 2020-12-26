/*! \file */

#ifndef TAUTIL_H
#define TAUTIL_H

#include "enums.h"

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
