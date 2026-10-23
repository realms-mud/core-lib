//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Centered Vitality", "A settled empty-handed posture "
        "grants +10 maximum hit points.", 15, 2, "grounded-base", "unarmed");
    addSpecification("bonus hit points", 10);
}
