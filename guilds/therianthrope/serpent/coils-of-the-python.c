//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Coils of the Python");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your familiarity with the serpent form "
        "enhances the crushing power and efficiency of your constriction.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 17
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/constrict.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 2);
    addSpecification("bonus constriction attack", 15);
}
