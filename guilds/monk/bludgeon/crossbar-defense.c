//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Crossbar Defense", "Present the staff across an incoming "
        "line, granting one defense and one soak with a primary staff or "
        "quarterstaff. This is mitigation, not an attack cancellation.",
        20, 3, "/guilds/monk/bludgeon/turning-staff.c", ([
        "equipment":([
            "type":"staff",
            "blueprint":({ "staff", "quarterstaff" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "self");
    addSpecification("bonus defense", 1);
    addSpecification("bonus soak", 1);
}
