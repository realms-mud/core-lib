//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lithe Form");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your panther form becomes supernaturally "
        "flexible, bending around attacks that would otherwise connect.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 21
        ]));

    addPrerequisite("/guilds/therianthrope/panther/evasive-maneuvers.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 3);
    addSpecification("bonus defense", 3);
    addSpecification("bonus soak", 1);
}
