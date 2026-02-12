//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Vicious Rake");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your panther form's strikes become more "
        "vicious, raking deeper wounds with each attack.");

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

    addPrerequisite("/guilds/therianthrope/panther/pounce.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 2);
}
