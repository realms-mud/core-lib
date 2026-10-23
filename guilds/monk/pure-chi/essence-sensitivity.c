//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Essence Sensitivity", "Feel the grain of internal energy "
        "before shaping it, improving magical essence by two.",
        10, 1, "/guilds/monk/pure-chi/chi-anatomy.c", ([]));
    addSpecification("bonus magical essence", 2);
}
