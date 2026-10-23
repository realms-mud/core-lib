//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Descending Lines", "Placing the descending arc adds "
        "three points to Descending Cut's damage.", 20, "descending-cut",
        "katana", "Descending Cut", "bonus", 3);
}
