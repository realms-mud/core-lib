//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Reaping Cut", "Carry the curved kama edge through "
        "one committed cut.", 15, "hook-alignment", "kama",
        "damage hit points", 18, 3, 12, 16, "reaping-lines");
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/kama/reaping-rhythm.c":4
    ]));
}
