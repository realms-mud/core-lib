//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Draw Alignment", "Align shoulder, elbow, and bow "
        "hand: +1 attack while wielding a primary bow.",
        15, 1, "archers-grip", "archery");
    addSpecification("bonus attack", 1);
}
