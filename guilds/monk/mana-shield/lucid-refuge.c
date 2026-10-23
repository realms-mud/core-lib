//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Lucid Refuge", "Read a hostile current without losing "
        "your own center. Ward Counterpulse gains ten percent of its "
        "base projection through its receiving research modifier.",
        30, 3, "/guilds/monk/mana-shield/ward-counterpulse.c", ([]));
    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([ "Ward Counterpulse":10 ]));
}
