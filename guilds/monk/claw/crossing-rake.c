//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Crossing Rake", "Cross the opponent's line with "
        "one tiger-claw thrust, not multiple strikes.",
        15, "claw-alignment", "claw", "damage hit points",
        16, 3, 10, 14, "crossing-talons");
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/claw/crossing-rhythm.c":4
    ]));
}
