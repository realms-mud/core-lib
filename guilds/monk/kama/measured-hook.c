//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Measured Hook", "Deliver one controlled kama cut "
        "and recover the hooked blade.", 10, "hooked-grip", "kama",
        "damage hit points", 12, 0, 8, 12, "hook-geometry");
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/kama/hook-economy.c":2
    ]));
}
