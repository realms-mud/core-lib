//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Quiet Intervals", "Recover the inward breath without "
        "rushing it. Restorative Chi Breath and Returning Current recover "
        "four seconds sooner.",
        20, 2, "/guilds/monk/pure-chi/circulation-theory.c", ([]));
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Restorative Chi Breath":4,
        "Returning Current":4 ]));
}
