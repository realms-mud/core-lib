//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Circular Mechanics", "Controlled rotational force adds "
        "three points to Drawn Circle's single-target damage.", 20,
        "drawn-circle", "katana", "Drawn Circle", "bonus", 3);
}
