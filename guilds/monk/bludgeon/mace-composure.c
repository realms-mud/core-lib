//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    addPrerequisite("/guilds/monk/bludgeon/contact-geometry.c",
        ([ "type":"research" ]));
    monkResearch("Mace Composure", "Combine contact geometry and haft "
        "shelter to remain composed in close combat. Grants two defense "
        "and one damage with a primary mace-school weapon.", 30, 4,
        "/guilds/monk/bludgeon/haft-shelter.c", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "self");
    addSpecification("bonus defense", 2);
    addSpecification("bonus damage", 1);
}
