//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Empty Hand", "A high-commitment finishing strike consumes "
        "sixteen stamina before efficiency training.", 25, "hammer-fist",
        "unarmed", "damage hit points", 30, 6, 16, 18, "empty-hand-theory");
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/unarmed/finishing-economy.c":2
    ]));
}
