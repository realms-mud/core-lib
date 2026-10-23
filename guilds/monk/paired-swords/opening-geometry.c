//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Opening Geometry", "Study the line behind a paired "
        "feint: adds three to Opening Cut's damage formula.", 20,
        "opening-cut", "paired-swords", "Opening Cut", "bonus", 3);
}
