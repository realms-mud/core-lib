//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Pressure", "Present two lines without adding "
        "an automatic attack: +1 attack.", 15, 2, "paired-grip",
        "paired-swords");
    addSpecification("bonus attack", 1);
}
