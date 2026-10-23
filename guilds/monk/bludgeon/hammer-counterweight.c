//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Hammer Counterweight", "Study the war hammer's head "
        "and haft as a counterweighted lever. Opens war hammer instruction "
        "and shortens Falling Head's cooldown by one second.", 10, 2,
        "/guilds/monk/bludgeon/impact-theory.c", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([ "Falling Head":1 ]));
}
