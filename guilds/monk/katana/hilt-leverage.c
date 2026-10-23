//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Hilt Leverage", "Efficient pressure adds three points "
        "to Hilt Check's stamina drain.", 10, "hilt-check",
        "katana", "Hilt Check", "bonus", 3);
}
