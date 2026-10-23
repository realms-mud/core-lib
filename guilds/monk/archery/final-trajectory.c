//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Final Trajectory", "Study the committed release: "
        "adds three to Final Draw's damage formula.", 30,
        "final-draw", "archery", "Final Draw", "bonus", 3);
}
