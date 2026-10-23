//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Archer's Grip", "Align the bow hand without twisting "
        "the release: +1 bow while wielding a primary bow.",
        10, 1, "root", "archery");
    addSpecification("bonus bow", 1);
}
