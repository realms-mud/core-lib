//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sky Sovereign");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your griffin form reaches mythical "
        "proportions, channeling the power of the legendary sky sovereigns "
        "with devastating attacks and keen precision.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 37
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/hippogriff.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 15);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 1);
    addSpecification("bonus soak", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Talon Rake": 25,
        "Diving Strike": 25,
        "Shrieking Gale": 25,
        "Sky Hammer": 25,
        "Tempest": 25
    ]));
}
