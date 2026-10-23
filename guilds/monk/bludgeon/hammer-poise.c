//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    addPrerequisite("/guilds/monk/bludgeon/anvil-geometry.c",
        ([ "type":"research" ]));
    monkResearch("Hammer Poise", "Combine anvil geometry with braced "
        "recovery to control a heavy head without overextension. Grants "
        "one strength and one defense with a primary war hammer.", 30, 4,
        "/guilds/monk/bludgeon/braced-recovery.c", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "self");
    addSpecification("bonus strength", 1);
    addSpecification("bonus defense", 1);
}
