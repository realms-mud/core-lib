//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Point of Release", "Refine the instant of release: "
        "adds three to Narrow-Line Shot's damage formula.", 20,
        "narrow-line-shot", "archery", "Narrow-Line Shot", "bonus", 3);
}
