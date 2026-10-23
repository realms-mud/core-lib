//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Leverage Study", "Advanced study of mass and lever arms "
        "adds one point to Measured Impact and Draining Impact. The "
        "principles apply only with a primary staff, mace, or hammer.",
        20, 3, "/guilds/monk/bludgeon/returning-guard.c", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Measured Impact":1,
        "Draining Impact":1
    ]));
}
