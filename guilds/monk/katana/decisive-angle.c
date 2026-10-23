//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Decisive Angle", "Selecting the finishing angle adds "
        "three points to Decisive Cut's damage.", 25, "decisive-cut",
        "katana", "Decisive Cut", "bonus", 3);
}
