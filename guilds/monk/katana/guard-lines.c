//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Guard Lines", "Maintaining a guarded line grants "
        "+1 defense with a primary katana.", 5, 1, "grip-discipline", "katana");
    addSpecification("bonus defense", 1);
}
