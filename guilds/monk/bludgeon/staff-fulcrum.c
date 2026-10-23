//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Staff Fulcrum", "Learn the changing fulcrum of a staff "
        "or quarterstaff. Opens staff instruction and shortens Sweeping "
        "Arc's cooldown by one second.", 10, 2,
        "/guilds/monk/bludgeon/impact-theory.c", ([
        "equipment":([
            "type":"staff",
            "blueprint":({ "staff", "quarterstaff" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([ "Sweeping Arc":1 ]));
}
