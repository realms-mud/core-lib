//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Grip Geometry", "Study tiring claw pressure: adds "
        "three to Gripping Rake's stamina-drain formula.", 15,
        "gripping-rake", "claw", "Gripping Rake", "bonus", 3);
}
