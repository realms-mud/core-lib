//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Momentum Mastery", "A master's uninterrupted recovery "
        "adds two points to the effects of Measured Impact and Draining "
        "Impact, and opens Unbroken Cadence.", 30, 4,
        "/guilds/monk/bludgeon/draining-impact.c", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Measured Impact":2,
        "Draining Impact":2
    ]));
}
