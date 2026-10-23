//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Archer's Endurance", "Recover efficiently after "
        "a demanding draw: +2 stamina healing rate with a primary bow.",
        25, 1, "draw-recovery", "archery");
    addSpecification("bonus heal stamina rate", 2);
}
