//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Blade Awareness", "Attending to the blade's reach "
        "grants +2 perception with a primary katana.", 5, 1,
        "measured-cut", "katana");
    addSpecification("bonus perception", 2);
}
