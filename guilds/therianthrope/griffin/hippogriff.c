//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hippogriff");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You channel the essence of the ancient "
        "hippogriff, gaining greater combat prowess and aerial dominance.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 31
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/shrieking-gale.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus defense", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Talon Rake": 25,
        "Diving Strike": 25,
        "Shrieking Gale": 25,
        "Sky Hammer": 25,
        "Tempest": 25
    ]));
}
