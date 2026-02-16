//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chimeric Resilience");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your chimera form grows more resilient, "
        "the composite nature of the beast granting endurance beyond any "
        "single creature.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 25
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/composite-hide.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus soak", 1);
    addSpecification("bonus hit points", 25);
}
