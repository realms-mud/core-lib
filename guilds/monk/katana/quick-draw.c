//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Quick Draw", "A short opening cut favors a six-second "
        "cooldown over the damage of heavier techniques.", 5,
        "grip-discipline", "katana", "damage hit points", 10, 3, 6, 6,
        "draw-theory");
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/katana/draw-economy.c":1
    ]));
}
