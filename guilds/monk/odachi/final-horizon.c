//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Final Horizon", "Commit to a demanding single-target "
        "finishing cut with the odachi's longest recovery.", 30,
        "longblade-mastery", "odachi", "damage hit points",
        44, 4, 28, 32, "longblade-final-theory");
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/odachi/final-horizon-economy.c":3
    ]));
}
