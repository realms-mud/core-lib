//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dragon's Fortitude");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The regenerative power of the dragon "
        "spirit enhances your natural healing while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 35
        ]));

    addPrerequisite("/guilds/therianthrope/dragon/draconic-resilience.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points rate", 2);
    addSpecification("bonus heal stamina rate", 1);
    addSpecification("bonus defense", 2);
}
