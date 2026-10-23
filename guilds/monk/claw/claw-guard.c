//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Claw Guard", "Turn an incoming line with the "
        "claw frame: +1 parry.", 10, 1, "claw-footwork", "claw");
    addSpecification("bonus parry", 1);
}
