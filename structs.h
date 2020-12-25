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
    unsigned short apWithFlags;
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
    CardConstInfo* constInfo;
    char unk_0x4[4];
    CardEffects cardEffects;
    char unk_0x30[8];
    short apBoost;
    short dpBoost;
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
     *  status & 0b10 is set when the unit is under opposition control, due to
     *  cards like Brain Control.
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
