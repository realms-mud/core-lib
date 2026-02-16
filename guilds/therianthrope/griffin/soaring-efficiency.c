//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soaring Efficiency");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your growing familiarity with the griffin "
        "form allows you to execute attacks with less effort.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 25
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/iron-feathers.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Talon Rake": 5,
        "Diving Strike": 5,
        "Shrieking Gale": 10,
        "Sky Hammer": 10,
        "Tempest": 15
    ]));
}
