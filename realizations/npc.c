//*****************************************************************************
// Class: npc
// File Name: npc.c
//
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/monster.c";
virtual inherit "/lib/modules/conversations.c";
virtual inherit "/lib/modules/crafting.c";

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfNpc()
{
    return 1;
}
