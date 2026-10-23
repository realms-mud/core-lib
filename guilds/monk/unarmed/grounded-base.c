//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Grounded Base", "Rooted weight distribution grants "
        "+1 soak in an empty-handed form.", 10, 2,
        "joint-conditioning", "unarmed");
    addSpecification("bonus soak", 1);
}
