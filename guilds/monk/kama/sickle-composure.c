//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Sickle Composure", "Resist overcommitting a "
        "hooked blade: +1 wisdom.", 25, 1, "sickle-guard", "kama");
    addSpecification("bonus wisdom", 1);
}
