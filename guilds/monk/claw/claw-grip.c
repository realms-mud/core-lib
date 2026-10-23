//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Claw Grip", "Align the tiger claws with the "
        "striking hand: +1 dagger.", 10, 1, "root", "claw");
    addSpecification("bonus dagger", 1);
}
