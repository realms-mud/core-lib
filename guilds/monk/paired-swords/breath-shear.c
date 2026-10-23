//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Breath Shear", "Pressure an opponent's concentration "
        "with the paired blades, draining spell points.", 15,
        "paired-pressure", "paired-swords", "damage spell points",
        12, 3, 10, 16, "paired-breath-theory");
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/paired-swords/paired-breath-economy.c":2
    ]));
}
