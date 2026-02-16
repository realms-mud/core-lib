//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hunter's Instinct");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The predatory instincts of the griffin "
        "sharpen, granting heightened combat awareness and precision while "
        "transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 23
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/raptor-fury.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus attack", 1);
    addSpecification("bonus damage", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Talon Rake": 15,
        "Diving Strike": 15,
        "Shrieking Gale": 15,
        "Sky Hammer": 15,
        "Tempest": 15
    ]));
}
