//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Silent Edge", "A master's single committed strike "
        "costs twenty stamina with a twenty-second cooldown.", 30,
        "master-balance", "katana", "damage hit points", 34, 4, 20, 20, 0);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/katana/silent-economy.c":3
    ]));
}
