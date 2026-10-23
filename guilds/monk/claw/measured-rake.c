//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Measured Rake", "Drive the tiger claws through "
        "one controlled close thrust.", 10, "claw-grip", "claw",
        "damage hit points", 10, 0, 8, 10, "rake-geometry");
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/claw/rake-economy.c":2
    ]));
}
