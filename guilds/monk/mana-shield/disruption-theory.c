//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Disruption Theory", "Study hostile currents against "
        "a stable ward. Opens reserve disruption and deliberate "
        "counterprojections rather than automatic retaliation.",
        20, 2, "/guilds/monk/mana-shield/deflecting-palm.c", ([]));
    addSpecification("related research", ({
        "/guilds/monk/mana-shield/interrupting-thread.c",
        "/guilds/monk/mana-shield/ward-counterpulse.c" }));
}
