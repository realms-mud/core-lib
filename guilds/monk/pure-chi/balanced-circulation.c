//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Balanced Circulation", "Reserve eight maximum spell "
        "points for continuous tissue repair. Gain two natural hit-point "
        "healing at the expense of two damage.",
        20, 3, "/guilds/monk/pure-chi/returning-current.c", ([]));
    addSpecification("scope", "self");
    addSpecification("spell point cost", 8);
    addSpecification("cooldown", 8);
    addSpecification("bonus heal hit points", 2);
    addSpecification("penalty to damage", 2);
    addSpecification("command template", "chi balanced circulation");
    addSpecification("use ability activate message",
        "A gentle repairing rhythm settles within ##InitiatorName##.");
    addSpecification("use ability deactivate message",
        "The repairing rhythm within ##InitiatorName## ends.");
}
