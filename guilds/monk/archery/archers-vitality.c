//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Archer's Vitality", "Endure the strain of prolonged "
        "bow practice: +6 maximum hit points while wielding a primary bow.",
        20, 1, "draw-conditioning", "archery");
    addSpecification("bonus hit points", 6);
}
