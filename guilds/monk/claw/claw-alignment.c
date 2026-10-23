//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Claw Alignment", "Align the tiger-claw points "
        "before striking: +1 attack.", 15, 1, "claw-grip", "claw");
    addSpecification("bonus attack", 1);
}
