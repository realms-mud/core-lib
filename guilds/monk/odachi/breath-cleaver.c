//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Breath Cleaver", "Use committed blade pressure to "
        "disrupt an opponent's spell-point reserve.", 15,
        "longblade-alignment", "odachi", "damage spell points",
        16, 3, 14, 20, "longblade-breath-theory");
}
