//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Hammer Return", "Recover a descending hammer along its "
        "natural arc. Falling Head, Burdening Blow, and Anvil Descent each "
        "cost one less stamina with a primary war hammer.", 15, 2,
        "/guilds/monk/bludgeon/falling-head.c", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Falling Head":1,
        "Burdening Blow":1,
        "Anvil Descent":1
    ]));
}
