//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Mental Abacus", "Rehearse energy paths as precise mental "
        "figures, granting one intelligence for deliberate shaping.",
        15, 2, "/guilds/monk/pure-chi/pulse-cadence.c", ([]));
    addSpecification("bonus intelligence", 1);
}
