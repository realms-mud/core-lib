//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Draw Economy", "Removing wasted motion reduces Quick "
        "Draw's authored stamina cost by one.", 15, "draw-theory",
        "katana", "Quick Draw", "decrease cost", 1);
}
