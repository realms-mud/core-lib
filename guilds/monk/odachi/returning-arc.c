//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Returning Arc", "Recover the odachi and commit one "
        "returning strike with demanding stamina and recovery costs.", 25,
        "horizon-geometry", "odachi", "damage hit points",
        38, 4, 24, 28, "longblade-return-theory");
}
