//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Unbroken Cadence", "Maintain an economical offensive "
        "cadence for one attack and one damage. Reserve eighteen stamina; "
        "each landed hit costs one stamina. Uses any primary bludgeon.",
        30, 4, "/guilds/monk/bludgeon/momentum-mastery.c", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("bonus attack", 1);
    addSpecification("bonus damage", 1);
    addSpecification("stamina point cost", 18);
    addSpecification("per hit landed cost", ([ "stamina points":1 ]));
    addSpecification("cooldown", 20);
    addSpecification("command template", "kata unbroken cadence");
    addSpecification("use ability activate message",
        "##InitiatorName## establish##InitiatorReflexive## an unbroken cadence.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## release##InitiatorReflexive## the unbroken cadence.");
}
