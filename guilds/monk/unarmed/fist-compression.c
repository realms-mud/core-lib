//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Fist Compression", "Compressing a short striking arc "
        "adds three points to Hammer Fist's damage.", 20, "hammer-fist",
        "unarmed", "Hammer Fist", "bonus", 3);
}
