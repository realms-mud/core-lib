//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Returning Cut", "Recover behind the companion blade "
        "and cut back along the opening.", 25, "crossing-cut",
        "paired-swords", "damage hit points", 26, 3, 16, 22, 0);
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/paired-swords/paired-return-rhythm.c":4
    ]));
}
