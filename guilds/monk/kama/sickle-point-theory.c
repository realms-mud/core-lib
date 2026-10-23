//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Sickle Point Theory", "Study the kama's pointed "
        "opening: adds three to Sickle Point's damage formula.", 20,
        "sickle-point", "kama", "Sickle Point", "bonus", 3);
}
