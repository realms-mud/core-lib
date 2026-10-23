//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Quiet Footwork", "Economical steps grant +1 dodge "
        "while both hands are empty.", 5, 1, "measured-palm", "unarmed");
    addSpecification("bonus dodge", 1);
}
