//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Still Heart", "A master's unhurried empty-handed "
        "awareness grants +1 wisdom.", 30, 3, "vital-reading", "unarmed");
    addSpecification("bonus wisdom", 1);
}
