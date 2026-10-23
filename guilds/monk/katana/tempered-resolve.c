//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Tempered Resolve", "Unshaken commitment grants "
        "+1 fortified with a primary katana.", 25, 3,
        "resilient-grip", "katana");
    addSpecification("bonus fortified", 1);
}
