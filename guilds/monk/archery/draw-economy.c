//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Bow Draw Economy", "Avoid wasted tension: reduces "
        "Measured Draw's stamina cost by two, without saving its arrow.",
        15, "draw-geometry", "archery", "Measured Draw", "decrease cost", 2);
}
