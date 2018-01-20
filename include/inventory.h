//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef inventory_h
#define inventory_h
 
#define PrimaryWeapon   0x00010000
#define OffhandWeapon   0x00020000
#define TwohandedWeapon 0x00030000
#define OnehandedWeapon 0x00010000
#define Shield          0x00020000

#define AllWielded    0x00030000
#define AllWorn       0x000033ff
#define Cloak         0x00000001
#define Helmet        0x00000002
#define Amulet        0x00000004
#define Belt          0x00000008
#define ArmGreaves    0x00000010
#define LegGreaves    0x00000020
#define Gloves        0x00000040
#define Bracers       0x00000080
#define Boots         0x00000100
#define Armor         0x00000200
#define Ring          0x00003000
#define Ring1         0x00001000
#define Ring2         0x00002000

#define Silently 1
#endif
