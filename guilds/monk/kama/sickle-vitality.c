//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Sickle Vitality", "Endure prolonged kama drills: "
        "+6 maximum hit points.", 20, 1, "sickle-conditioning", "kama");
    addSpecification("bonus hit points", 6);
}
