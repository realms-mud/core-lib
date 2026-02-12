//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Evasive Maneuvers");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your panther form becomes nearly "
        "impossible to pin down, weaving through attacks with ease.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 17
        ]));

    addPrerequisite("/guilds/therianthrope/panther/nimble-recovery.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 3);
    addSpecification("bonus soak", 1);
    addSpecification("bonus resist physical", 5);
}
