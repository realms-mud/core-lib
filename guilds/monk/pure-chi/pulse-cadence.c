//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Pulse Cadence", "Time broad projections between breaths. "
        "Driving Wave recovers two seconds sooner.",
        15, 2, "/guilds/monk/pure-chi/pulse-geometry.c", ([]));
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([ "Driving Wave":2 ]));
}
