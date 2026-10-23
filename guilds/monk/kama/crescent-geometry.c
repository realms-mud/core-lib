//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Crescent Geometry", "Study the broad sickle arc: "
        "adds three to Crescent Reap's damage formula.", 20,
        "crescent-reap", "kama", "Crescent Reap", "bonus", 3);
}
