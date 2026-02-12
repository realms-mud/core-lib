//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nimble Recovery");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The panther's natural vitality allows "
        "you to recover stamina more quickly while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 13
        ]));

    addPrerequisite("/guilds/therianthrope/panther/sleek-coat.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal stamina rate", 3);
    addSpecification("bonus heal hit points rate", 1);
    addSpecification("bonus defense", 2);
    addSpecification("bonus dodge", 2);
}
