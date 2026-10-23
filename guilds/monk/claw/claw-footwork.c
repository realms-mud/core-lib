//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Claw Footwork", "Stay mobile behind the short "
        "tiger-claw guard: +1 dodge.", 10, 1, "claw-grip", "claw");
    addSpecification("bonus dodge", 1);
}
