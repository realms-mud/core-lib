//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Recovery", "Relax the unused line between "
        "exchanges: +1 stamina healing rate.", 15, 2, "paired-guard",
        "paired-swords");
    addSpecification("bonus heal stamina rate", 1);
}
