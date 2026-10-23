//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Rooted Cut", "Grounding each cut grants +1 ordinary "
        "damage with a primary katana.", 10, 2, "grip-discipline", "katana");
    addSpecification("bonus damage", 1);
}
