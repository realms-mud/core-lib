//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Sickle Endurance", "Recover breath without "
        "dropping the kama guard: +2 stamina healing rate.",
        25, 1, "hook-recovery", "kama");
    addSpecification("bonus heal stamina rate", 2);
}
