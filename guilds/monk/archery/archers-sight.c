//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Archer's Sight", "Coordinate eye and release "
        "without haste: +1 dexterity while wielding a primary bow.",
        20, 1, "archers-distance", "archery");
    addSpecification("bonus dexterity", 1);
}
