//*****************************************************************************
// Class: player
// File Name: player.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: TBD
//
//*****************************************************************************
virtual inherit "/lib/realizations/living.c";
virtual inherit "/lib/modules/guilds.c";
virtual inherit "/lib/modules/parties.c";
virtual inherit "/lib/modules/quests.c";
virtual inherit "/lib/modules/traits.c";
virtual inherit "/lib/modules/research.c";

public nomask int isRealizationOfPlayer()
{
    return 1;
}

public nomask int attackIsDeath(object murderer)
{
    
}

