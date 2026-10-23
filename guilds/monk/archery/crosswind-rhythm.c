//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Crosswind Rhythm", "Recover smoothly from oblique "
        "releases: reduces Crosswind Shot's cooldown by four seconds.",
        20, "crosswind-geometry", "archery", "Crosswind Shot",
        "decrease cooldown", 4);
}
