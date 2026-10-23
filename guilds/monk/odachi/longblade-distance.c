//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Distance", "Judge an opening before "
        "committing the odachi: +1 perception.", 10, 1, "root", "odachi");
    addSpecification("bonus perception", 1);
}
