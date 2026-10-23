//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Companion Check", "Press the opponent's guard with "
        "the paired blades to drain stamina, not hit points.", 10,
        "companion-grip", "paired-swords", "damage stamina points",
        10, 2, 8, 14, "companion-leverage");
}
