//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Empty Hand Theory", "Uniting intention and alignment "
        "adds three points to Empty Hand's damage.", 25, "empty-hand",
        "unarmed", "Empty Hand", "bonus", 3);
}
