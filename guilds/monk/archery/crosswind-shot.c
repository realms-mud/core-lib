//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Crosswind Shot", "Release one arrow along a measured "
        "oblique line. No weather-dependent bonus is applied.",
        15, "archers-distance", "archery", "damage hit points",
        20, 3, 14, 18, "crosswind-geometry");
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/archery/crosswind-rhythm.c":4
    ]));
}
