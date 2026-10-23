//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Weighted Rhythm", "Maintain a measured mace rhythm for "
        "one attack and one damage. Reserve ten stamina and spend one "
        "stamina per landed hit; requires a mace-school primary.", 15, 2,
        "/guilds/monk/bludgeon/compact-blow.c", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("bonus attack", 1);
    addSpecification("bonus damage", 1);
    addSpecification("stamina point cost", 10);
    addSpecification("per hit landed cost", ([ "stamina points":1 ]));
    addSpecification("cooldown", 12);
    addSpecification("command template", "kata weighted rhythm");
    addSpecification("use ability activate message",
        "##InitiatorName## adopt##InitiatorReflexive## a weighted mace rhythm.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## release##InitiatorReflexive## the weighted rhythm.");
}
