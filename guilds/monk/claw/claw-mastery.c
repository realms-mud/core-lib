//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Claw Mastery", "Unify the tiger-claw grip and "
        "close footwork: +2 dagger.", 30, 1, "claw-composure", "claw");
    addSpecification("bonus dagger", 2);
}
