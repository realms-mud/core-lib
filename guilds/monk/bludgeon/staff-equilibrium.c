//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    addPrerequisite("/guilds/monk/bludgeon/long-reach-geometry.c",
        ([ "type":"research" ]));
    monkResearch("Staff Equilibrium", "A master combines reach geometry "
        "and crossbar defense into a stable staff stance, granting one "
        "attack and two dodge while a staff or quarterstaff is primary.",
        30, 4, "/guilds/monk/bludgeon/crossbar-defense.c", ([
        "equipment":([
            "type":"staff",
            "blueprint":({ "staff", "quarterstaff" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "self");
    addSpecification("bonus attack", 1);
    addSpecification("bonus dodge", 2);
}
