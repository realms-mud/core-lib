//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Resilient Grip", "Relaxed forearms grant +10 maximum "
        "stamina with a primary katana.", 15, 2, "rooted-cut", "katana");
    addSpecification("bonus stamina points", 10);
}
