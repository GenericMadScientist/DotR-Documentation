/*! \file */

#ifndef GLOBAL_H
#define GLOBAL_H

/** @brief Adds a unit to a flaglist.
 *
 *  A flaglist is a way of representing a flag for every unit. The lowest bit
 *  is the Yorkist Leader, going up to Yorkist unit 10, then Lancastrian Leader,
 *  going up to Lancastrian unit 10. This function copies flagList, sets the bit
 *  corresponding to (side, pos), then returns the new flaglist.
 *
 *  @param flagList The flaglist to add the unit to
 *  @param side The side of the unit to add
 *  @param pos The position of the unit to add
 *  @return The modified flaglist
 */
int ConvUnitIDtoFlagList(int flagList, int side, int pos);

/** @brief Bounds a value in a way depending on the cap.
 *
 *  If the cap is 6, 7, 500, 1500, or 9999, GetCap returns min(cap, value). If
 *  the cap is 0 or 1, GetCap returns max(cap, value). Otherwise 0 is returned.
 *
 *  @param cap The cap to apply
 *  @param value The value to cap
 *  @return The capped value
 */
int GetCap(int cap, int value);

/** @brief Clamps a stat between 0 and 9999 inclusive.
 *
 *  @param stat The stat to clamp
 *  @return min(max(stat, 0), 9999)
 */
int GetParCap(int stat);

#endif
