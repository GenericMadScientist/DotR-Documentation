/*! \file */

#ifndef STRUCTS_H
#define STRUCTS_H

struct CardConstInfo {
    unsigned char kind;
    unsigned char kindOfs;
    unsigned char lvAttr;
    unsigned char deckCost;
    unsigned short effectId;
    unsigned short xaxId;
    /*! A bitset containing the default AP and some flags.
     *  apWithFlags & 0x1FFF is the default AP.
     *  apWithFlags & 0x2000 is if the card has an image in DATA/PICPACK.MRG.
     *  apWithFlags & 0x4000 is if the card's password will work.
     *  apWIthFlags & 0x8000 is if the card can be received from reincarnation.
     */
    unsigned short apWithFlags;
    /*! A bitset containing the default DP and some flags.
     *  dpWithFlags & 0x1FFF is the default DP.
     *  dpWithFlags & 0x2000 is if the card appears in slots normally.
     *  dpWithFlags & 0x4000 is if the card is a slot rare, with the exception
     *  of Brain Control. This is ignored for the special slot rares.
     *  dpWIthFlags & 0x8000 is not understood.
     */
    unsigned short dpWithFlags;
    unsigned char password[8];
};

struct Effect {
    unsigned int type;
    unsigned int data;
};

union CardEffects {
    Effect effects[5];
    unsigned short leaderAbilities[20];
};

/*! This struct comes up in SzModel_GetModelType. */
struct Model {
    char unk_0x0[499];
    /*! The model type returned by SzModel_GetModelType. */
    signed char type;
    char unk_0x1F4[27];
};

/*! The main struct that represents a Deck Leader or card on the field. */
struct Unit {
    /*! The CardConstInfo referring to the original data for a card. */
    CardConstInfo* constInfo;
    char unk_0x4[4];
    CardEffects cardEffects;
    char unk_0x30[8];
    /*! The total boosts and debuffs being applied to the card's attack. Does
     *  not include terrain or leader effects, or Shapesnatch's effect. */
    short apBoost;
    /*! The total boosts and debuffs being applied to the card's defense. Does
     *  not include terrain or leader effects, or Shapesnatch's effect. */
    short dpBoost;
    /*! The card number of the unit (000 BEWD -> 853 Dark Magic Ritual). */
    unsigned short cardNo;
    /*! The kind of the unit. See Kind enum. */
    unsigned char kind;
    /*! The attribute of the unit. See Attribute enum. */
    unsigned char attr;
    /*! The column the unit is on, from 0 to 6 inclusive. */
    unsigned char locCol;
    /*! The row the unit is on, from 0 to 6 inclusive. */
    unsigned char locRow;
    char unk_0x42[2];
    /*! The side that normally controls the unit. */
    unsigned char side;
    /*! SzDuel_GetUnit checks if this is greater than 10. */
    unsigned char slot;
    char unk_0x46;
    /*! Starts at 0 for the first summoned card, 1 for the next, etc. */
    unsigned char summonOrder;
    unsigned char lvRev;
    unsigned char curseRest;
    unsigned char spellRest;
    unsigned char delayCount;
    char unk_0x4C[4];
    unsigned char ctlGoalC;
    unsigned char ctlGoalM;
    char unk_0x52;
    unsigned char ctlRateM;
    unsigned char openRate;
    char unk_0x55[2];
    /*! A series of flags.
     *  status & 0b000001 is set if the unit has moved.
     *  status & 0b000010 is set when the unit is under opposition control, due
     *  to cards like Brain Control.
     *  status & 0b000100 is set if the card is showing as face-up.
     *  status & 0b001000 is set if the card is showing as being in defense
     *  position.
     *  status & 0b010000 is set if the card is actually face-up.
     *  status & 0b100000 is set if the card is actually in defense position.
     */
    unsigned char status;
    char unk_0x58[4];
};

/*! The main struct that represents a square on the field. */
struct MapInfo {
    Unit* unit;
    char unk_0x04[16];
    unsigned short fieldRate;
    /*! Stores the terrain type. See Field enum. */
    unsigned char field;
    char unk_0x17[5];
}

#endif
