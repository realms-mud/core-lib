//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Final Rake Economy", "Avoid wasted effort in a "
        "heavy claw thrust: Final Rake costs three less stamina.",
        30, "final-rake-theory", "claw", "Final Rake", "decrease cost", 3);
}
