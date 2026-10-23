//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Grip Discipline", "Correct pressure grants +1 hand "
        "and a half sword with a primary katana.", 5, 1,
        "measured-cut", "katana");
    addSpecification("bonus hand and a half sword", 1);
}
