//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Long Reach Geometry", "Study the staff's contact angles "
        "at full extension. Adds two damage to Sweeping Arc and Horizon "
        "Stroke and opens the staff's master technique.", 25, 3,
        "/guilds/monk/bludgeon/pressing-shaft.c", ([
        "equipment":([
            "type":"staff",
            "blueprint":({ "staff", "quarterstaff" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Sweeping Arc":2,
        "Horizon Stroke":2
    ]));
}
