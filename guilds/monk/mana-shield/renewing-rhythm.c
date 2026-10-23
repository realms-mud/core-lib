//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Renewing Rhythm", "Fit recovery into the ward's natural "
        "rhythm. Ward Mending recovers four seconds sooner and Measured "
        "Renewal six seconds sooner.",
        20, 2, "/guilds/monk/mana-shield/defensive-timing.c", ([]));
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Ward Mending":4,
        "Measured Renewal":6 ]));
}
