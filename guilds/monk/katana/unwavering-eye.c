//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Unwavering Eye", "Maintaining deliberate attention "
        "grants +1 wisdom with a primary katana.", 15, 2,
        "settled-edge", "katana");
    addSpecification("bonus wisdom", 1);
}
