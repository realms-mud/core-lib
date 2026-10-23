//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Final Draw Economy", "Reduce excess muscular effort: "
        "Final Draw costs three less stamina but still consumes an arrow.",
        30, "final-trajectory", "archery", "Final Draw", "decrease cost", 3);
}
