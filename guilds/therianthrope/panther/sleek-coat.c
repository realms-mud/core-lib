//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sleek Coat");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your panther form's coat becomes sleek "
        "and tough, offering modest protection without hindering agility.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 9
        ]));

    addPrerequisite("/guilds/therianthrope/panther/feline-agility.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus soak", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus defense", 2);
}
