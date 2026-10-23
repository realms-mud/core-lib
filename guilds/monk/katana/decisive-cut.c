//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Decisive Cut", "A costly finishing cut commits sixteen "
        "stamina and an eighteen-second cooldown.", 25, "descending-lines",
        "katana", "damage hit points", 28, 5, 16, 18, "decisive-angle");
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/katana/decisive-rhythm.c":4
    ]));
}
