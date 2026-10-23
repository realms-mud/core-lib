//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Bow Leverage", "Study exhausting lines: adds three "
        "to Arresting Shot's stamina-drain formula.", 10,
        "arresting-shot", "archery", "Arresting Shot", "bonus", 3);
}
