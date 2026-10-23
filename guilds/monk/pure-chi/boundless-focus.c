//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Boundless Focus", "Reserve twelve maximum spell points "
        "to sharpen spellcraft by four. Outward vigilance suffers two "
        "defense while the inner calculation is maintained.",
        30, 4, "/guilds/monk/pure-chi/essence-weaving.c", ([]));
    addSpecification("scope", "self");
    addSpecification("spell point cost", 12);
    addSpecification("cooldown", 10);
    addSpecification("bonus spellcraft", 4);
    addSpecification("penalty to defense", 2);
    addSpecification("command template", "chi boundless focus");
    addSpecification("use ability activate message",
        "##InitiatorName##'s gaze turns inward in boundless focus.");
    addSpecification("use ability deactivate message",
        "##InitiatorName##'s attention returns to the world.");
}
