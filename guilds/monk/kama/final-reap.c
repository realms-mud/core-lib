//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Final Reap", "Commit stamina and recovery time "
        "to one heavy kama cut.", 30, "sickle-mastery", "kama",
        "damage hit points", 34, 3, 22, 28, "final-reap-theory");
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/kama/final-reap-economy.c":3
    ]));
}
