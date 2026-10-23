//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Draw Geometry", "Study the line of release: adds "
        "three to Measured Draw's damage formula.", 10,
        "measured-draw", "archery", "Measured Draw", "bonus", 3);
}
