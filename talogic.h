/*! \file */

#ifndef TALOGIC_H
#define TALOGIC_H

/** @brief Returns the number of elements in units.
 *
 *  This function loops over the first 22 unsigned shorts pointed to by units
 *  and returns the number of them that are unequal to 0xFFFF.
 *
 *  @param units The units to count
 *  @return The number of valid ownerIds in units
 */
int TaLogic_GetUnitCtlLstLen(unsigned short* units);

#endif
