//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Hook Geometry", "Study the kama's curved line: adds "
        "three to Measured Hook's damage formula.", 10,
        "measured-hook", "kama", "Measured Hook", "bonus", 3);
}
