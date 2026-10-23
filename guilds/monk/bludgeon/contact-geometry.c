//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Contact Geometry", "Study how the mace head meets a "
        "surface. Adds ten percent to Compact Blow and Centerline Crush "
        "and opens the mace's master technique; grants no armor bypass.",
        25, 3, "/guilds/monk/bludgeon/taxing-contact.c", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Compact Blow":10,
        "Centerline Crush":10
    ]));
}
