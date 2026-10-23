//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Breath Timing", "Timing a strike against concentration "
        "adds three points to Breath Cut's spell-point drain.", 15,
        "breath-cut", "katana", "Breath Cut", "bonus", 3);
}
