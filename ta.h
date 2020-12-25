/*! \file */

#ifndef TA_H
#define TA_H

#include "structs.h"

/** @brief Gets the side controlling a unit.
 *
 *  If unit is NULL, the function returns -1. Otherwise it returns the side
 *  controlling unit, taking into account if the unit is currently controlled
 *  by cards like Brain Control.
 *
 *  @param unit The unit to check
 *  @return The side controlling unit
 */
int Ta_IsUnitControl2(Unit *unit);

#endif
