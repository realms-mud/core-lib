//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Archer's Mastery", "Integrate grip, footing, and "
        "release: +2 bow while wielding a primary bow.",
        30, 1, "archers-composure", "archery");
    addSpecification("bonus bow", 2);
}
