//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Final Rake", "Commit stamina to one forceful "
        "tiger-claw thrust followed by deliberate recovery.",
        30, "claw-mastery", "claw", "damage hit points",
        30, 3, 20, 26, "final-rake-theory");
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/claw/final-rake-economy.c":3
    ]));
}
