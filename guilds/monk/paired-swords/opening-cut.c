//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Opening Cut", "Use a companion-blade feint to support "
        "one committed katana strike.", 20, "crossing-lines",
        "paired-swords", "damage hit points", 22, 3, 14, 18,
        "opening-geometry");
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/paired-swords/paired-opening-economy.c":2
    ]));
}
