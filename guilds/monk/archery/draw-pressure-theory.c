//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Draw Pressure Theory", "Study tiring responses to "
        "arrows: adds three to Burdening Shot's stamina-drain formula.",
        15, "burdening-shot", "archery", "Burdening Shot", "bonus", 3);
}
