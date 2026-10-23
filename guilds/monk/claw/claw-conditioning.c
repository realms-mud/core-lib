//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Claw Conditioning", "Condition the hands for "
        "tiger-claw drills: +5 maximum stamina.",
        15, 1, "claw-footwork", "claw");
    addSpecification("bonus stamina points", 5);
}
