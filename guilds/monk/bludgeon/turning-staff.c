//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Turning Staff", "Maintain a turning staff guard for "
        "two parry. Reserve eight stamina and spend one stamina on each "
        "received hit. Requires a primary staff or quarterstaff.", 15, 2,
        "/guilds/monk/bludgeon/sweeping-arc.c", ([
        "equipment":([
            "type":"staff",
            "blueprint":({ "staff", "quarterstaff" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("bonus parry", 2);
    addSpecification("stamina point cost", 8);
    addSpecification("per hit received cost", ([ "stamina points":1 ]));
    addSpecification("cooldown", 12);
    addSpecification("command template", "kata turning staff");
    addSpecification("use ability activate message",
        "##InitiatorName## begin##InitiatorReflexive## a turning staff guard.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## lower##InitiatorReflexive## the turning staff guard.");
}
