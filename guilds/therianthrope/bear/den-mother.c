//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Den Mother");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The protective instincts of the bear "
        "spirit enhance your natural healing and resilience while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/bear/bear-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 13
        ]));

    addPrerequisite("/guilds/therianthrope/bear/iron-fur.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points rate", 2);
    addSpecification("bonus heal stamina rate", 1);
    addSpecification("bonus defense", 2);
}
