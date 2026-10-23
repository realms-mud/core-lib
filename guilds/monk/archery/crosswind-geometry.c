//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Crosswind Geometry", "Study the oblique release: "
        "adds three to Crosswind Shot's damage formula.", 15,
        "crosswind-shot", "archery", "Crosswind Shot", "bonus", 3);
}
