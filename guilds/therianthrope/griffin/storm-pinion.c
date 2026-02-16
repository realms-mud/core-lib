//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Storm Pinion");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your feathers crackle with the fury of "
        "the storm, making your wind-based attacks devastatingly effective.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 41
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/tempest.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 2);
    addSpecification("bonus resist air", 5);
    addSpecification("bonus resist cold", 5);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Talon Rake": 25,
        "Diving Strike": 20,
        "Shrieking Gale": 30,
        "Sky Hammer": 20,
        "Tempest": 30
    ]));
}
