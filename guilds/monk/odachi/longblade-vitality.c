//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Vitality", "Endure the demands of heavy "
        "blade practice: +8 maximum hit points.", 20, 2,
        "longblade-conditioning", "odachi");
    addSpecification("bonus hit points", 8);
}
