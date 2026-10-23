//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Binding Geometry", "Study exhausting kama angles: "
        "adds three to Binding Hook's stamina-drain formula.", 15,
        "binding-hook", "kama", "Binding Hook", "bonus", 3);
}
