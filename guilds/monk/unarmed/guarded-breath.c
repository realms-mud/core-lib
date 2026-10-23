//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Guarded Breath", "Breathing through defensive transitions "
        "grants +1 defense while empty-handed.", 10, 2,
        "quiet-footwork", "unarmed");
    addSpecification("bonus defense", 1);
}
