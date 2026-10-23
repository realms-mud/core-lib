//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Joint Conditioning", "Conditioned joints grant +1 armor "
        "class in an empty-handed fighting form.", 5, 1,
        "open-hand-guard", "unarmed");
    addSpecification("bonus armor class", 1);
}
