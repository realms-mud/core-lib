//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Griffin Apotheosis");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your griffin form transcends the merely "
        "physical, becoming an avatar of aerial perfection with devastating "
        "precision and lethal dives.");

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

    addPrerequisite("/guilds/therianthrope/griffin/sky-sovereign.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus air enchantment", 2);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Talon Rake": 25,
        "Diving Strike": 25,
        "Shrieking Gale": 25,
        "Sky Hammer": 25,
        "Tempest": 25
    ]));
}
