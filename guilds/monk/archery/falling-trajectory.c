//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Falling Trajectory", "Study descending lines: "
        "adds three to Descending Shot's damage formula.", 20,
        "descending-shot", "archery", "Descending Shot", "bonus", 3);
}
