//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Paired Opening Economy", "Waste less effort behind "
        "the feint: reduce Opening Cut's authored stamina cost by two.",
        25, "opening-geometry", "paired-swords", "Opening Cut",
        "decrease cost", 2);
}
