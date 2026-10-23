//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Staff Economy", "Use the staff's returning end rather "
        "than resetting the whole weapon. Sweeping Arc, Pressing Shaft, "
        "and Horizon Stroke each cost one less stamina.", 15, 2,
        "/guilds/monk/bludgeon/sweeping-arc.c", ([
        "equipment":([
            "type":"staff",
            "blueprint":({ "staff", "quarterstaff" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Sweeping Arc":1,
        "Pressing Shaft":1,
        "Horizon Stroke":1
    ]));
}
