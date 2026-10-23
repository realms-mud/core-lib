//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Endurance", "Waste less breath resetting "
        "the long blade: +2 stamina healing rate.", 25, 3,
        "longblade-recovery", "odachi");
    addSpecification("bonus heal stamina rate", 2);
}
