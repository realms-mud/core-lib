//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Anvil Geometry", "Study how a descending hammer "
        "transfers force at contact. Adds two damage to Falling Head and "
        "Anvil Descent and opens master-level war hammer work.", 25, 3,
        "/guilds/monk/bludgeon/burdening-blow.c", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Falling Head":2,
        "Anvil Descent":2
    ]));
}
