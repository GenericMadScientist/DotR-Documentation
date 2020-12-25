/*! \file */

#ifndef GLOBAL_H
#define GLOBAL_H

/** @brief Clamps a stat between 0 and 9999 inclusive.
 *
 *  @param stat The stat to clamp
 *  @return min(max(stat, 0), 9999)
 */
int GetParCap(int stat);

#endif
