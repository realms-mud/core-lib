//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Rooted Anvil", "Brace behind a war hammer for two soak "
        "and one attack. Reserve twelve stamina and spend one stamina "
        "per received hit. Does not prevent movement or enemy actions.",
        15, 2, "/guilds/monk/bludgeon/falling-head.c", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("bonus soak", 2);
    addSpecification("bonus attack", 1);
    addSpecification("stamina point cost", 12);
    addSpecification("per hit received cost", ([ "stamina points":1 ]));
    addSpecification("cooldown", 15);
    addSpecification("command template", "kata rooted anvil");
    addSpecification("use ability activate message",
        "##InitiatorName## assume##InitiatorReflexive## a rooted anvil stance.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## relax##InitiatorReflexive## the rooted anvil stance.");
}
