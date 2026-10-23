//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Contemplative Focus", "Practice observing an impulse "
        "without obeying it. Your settled judgment grants one wisdom.",
        10, 1, "/guilds/monk/pure-chi/chi-anatomy.c", ([]));
    addSpecification("bonus wisdom", 1);
}
