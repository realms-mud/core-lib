//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Polished Defense", "Minimizing exposed angles grants "
        "+1 armor class with a primary katana.", 20, 2,
        "traveling-guard", "katana");
    addSpecification("bonus armor class", 1);
}
