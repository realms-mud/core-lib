//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Master Balance", "A master's precise weight transfer "
        "grants +1 dexterity with a primary katana.", 30, 3,
        "measured-distance", "katana");
    addSpecification("bonus dexterity", 1);
}
