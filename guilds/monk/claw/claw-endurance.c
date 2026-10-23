//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Claw Endurance", "Recover breath while "
        "maintaining the short guard: +2 stamina healing rate.",
        25, 1, "claw-recovery", "claw");
    addSpecification("bonus heal stamina rate", 2);
}
