//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Rising Lines", "Studying ascending cuts adds three "
        "points to Rising Cut's damage.", 15, "rising-cut",
        "katana", "Rising Cut", "bonus", 3);
}
