//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Close Haft Grip", "A compact mace grip grants two mace "
        "skill with a primary mace, flanged mace, or morning star. It "
        "places no additional restriction on the offhand.", 10, 2,
        "/guilds/monk/bludgeon/mace-head-alignment.c", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "self");
    addSpecification("bonus mace", 2);
}
