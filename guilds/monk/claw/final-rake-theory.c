//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Final Rake Theory", "Study the committed thrust: "
        "adds three to Final Rake's damage formula.", 30,
        "final-rake", "claw", "Final Rake", "bonus", 3);
}
