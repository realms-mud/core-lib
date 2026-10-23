//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Returning Guard", "Maintain a compact recovery guard for "
        "one parry and one defense. Reserve eight stamina; each received "
        "hit costs one stamina. Requires a primary bludgeon.", 15, 2,
        "/guilds/monk/bludgeon/recovery-economy.c", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("bonus parry", 1);
    addSpecification("bonus defense", 1);
    addSpecification("stamina point cost", 8);
    addSpecification("per hit received cost", ([ "stamina points":1 ]));
    addSpecification("cooldown", 10);
    addSpecification("command template", "kata returning guard");
    addSpecification("use ability activate message",
        "##InitiatorName## settle##InitiatorReflexive## into a returning guard.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## relax##InitiatorReflexive## the returning guard.");
}
