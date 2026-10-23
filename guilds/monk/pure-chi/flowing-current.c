//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Flowing Current", "Reserve six maximum spell points to "
        "maintain a smooth current, improving magical essence by three.",
        10, 2, "/guilds/monk/pure-chi/essence-sensitivity.c", ([]));
    addSpecification("scope", "self");
    addSpecification("spell point cost", 6);
    addSpecification("cooldown", 6);
    addSpecification("bonus magical essence", 3);
    addSpecification("command template", "chi flowing current");
    addSpecification("use ability activate message",
        "A smooth current gathers within ##InitiatorName##.");
    addSpecification("use ability deactivate message",
        "The current within ##InitiatorName## subsides.");
}
