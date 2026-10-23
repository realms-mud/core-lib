//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Linked Lines", "Understand how the companion blade "
        "supports a cut: adds three to Linked Cut's damage formula.",
        10, "linked-cut", "paired-swords", "Linked Cut", "bonus", 3);
}
