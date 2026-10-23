//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Measured Draw", "Release one arrow with a controlled "
        "draw and deliberate recovery.", 10, "archers-grip", "archery",
        "damage hit points", 14, 0, 10, 14, "draw-geometry");
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/archery/draw-economy.c":2
    ]));
}
