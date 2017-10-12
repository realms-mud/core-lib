//*****************************************************************************
// Class: henchman
// File Name: henchman.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/living.c";
virtual inherit "/lib/modules/guilds.c";
virtual inherit "/lib/modules/quests.c";
virtual inherit "/lib/modules/traits.c";
virtual inherit "/lib/modules/research.c";
virtual inherit "/lib/modules/conversations.c";

public nomask int isRealizationOfHenchman()
{
    return 1;
}
//TODO [249]: To, in fact, do.

