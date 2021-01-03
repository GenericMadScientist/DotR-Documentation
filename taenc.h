/*! \file */

#ifndef TAENC_H
#define TAENC_H

/** @brief Address 29D4E0
 *
 *  The EquipData for all 49 equips.
 */
extern EquipData EnchData;

/** @brief Address 29D580
 *
 *  Stores the equips that work on each card. The least significant bit of the
 *  first byte is for the first equip, next bit is for the second equip, and so
 *  on. Toon terrain compatibility is also stored here as the bit after the
 *  equip ones.
 */
extern unsigned char EnchMatch[683][7];

/** @brief Returns a random elf.
 *
 *  This is for Wing Egg Elf + Insect Imitation. The (equally likely)
 *  possibilities are Ancient Elf, Dancing Elf, Dark Elf, Gemini Elf, Mystical
 *  Elf, and Wing Egg Elf.
 *
 *  @return A random elf
 */
int TaEnc_GetRandomElf(void);

#endif
