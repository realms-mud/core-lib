//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Final Reap Economy", "Avoid wasted effort in a "
        "heavy kama cut: Final Reap costs three less stamina.",
        30, "final-reap-theory", "kama", "Final Reap", "decrease cost", 3);
}
