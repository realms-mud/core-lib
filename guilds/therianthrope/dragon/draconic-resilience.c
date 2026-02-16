//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Draconic Resilience");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your dragon form grows more resilient, "
        "the thick silver scales absorbing impacts with ease.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 31
        ]));

    addPrerequisite("/guilds/therianthrope/dragon/silver-scales.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus soak", 1);
    addSpecification("bonus hit points", 25);
}
