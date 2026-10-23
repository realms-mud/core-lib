//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Point Alignment", "A precisely aligned point adds "
        "three points to Needle Thrust's damage.", 25, "needle-thrust",
        "katana", "Needle Thrust", "bonus", 3);
}
