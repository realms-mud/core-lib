//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Final Draw", "Commit one arrow and substantial "
        "stamina to a heavy release with a long recovery.",
        30, "archers-mastery", "archery", "damage hit points",
        36, 3, 24, 30, "final-trajectory");
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/archery/final-draw-economy.c":3
    ]));
}
