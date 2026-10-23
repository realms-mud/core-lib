//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Recovery Economy", "An adept wastes less motion returning "
        "to guard: Measured Impact and Draining Impact cost one less "
        "stamina while a primary bludgeon is equipped.", 15, 2,
        "/guilds/monk/bludgeon/grounded-footwork.c", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Measured Impact":1,
        "Draining Impact":1
    ]));
}
