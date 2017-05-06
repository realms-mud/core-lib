//*****************************************************************************
// Class: npc
// File Name: npc.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: TBD
//
//*****************************************************************************
virtual inherit "/lib/realizations/monster.c";
virtual inherit "/lib/modules/conversationTree.c";

public nomask int isRealizationOfNpc()
{
    return 1;
}

