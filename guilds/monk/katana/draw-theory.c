//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Draw Theory", "Blade alignment adds three points to "
        "Quick Draw's damage.", 10, "quick-draw", "katana",
        "Quick Draw", "bonus", 3);
}
