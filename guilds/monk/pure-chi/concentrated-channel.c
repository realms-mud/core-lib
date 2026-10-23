//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Concentrated Channel", "Reserve eight maximum spell "
        "points to reinforce energy attacks, at a cost of one defense.",
        15, 3, "/guilds/monk/pure-chi/flowing-current.c", ([]));
    addSpecification("scope", "self");
    addSpecification("spell point cost", 8);
    addSpecification("cooldown", 8);
    addSpecification("bonus energy attack", 2);
    addSpecification("penalty to defense", 1);
    addSpecification("command template", "chi concentrated channel");
    addSpecification("use ability activate message",
        "Chi gathers sharply along ##InitiatorName##'s limbs.");
    addSpecification("use ability deactivate message",
        "The sharp energy around ##InitiatorName## disperses.");
}
