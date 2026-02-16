//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Celestial Aegis");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your plumage takes on a celestial sheen, "
        "granting divine-like protection and enhancing your wind attacks.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 49
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/empyrean-ward.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus air enchantment", 3);
    addSpecification("bonus damage", 3);
    addSpecification("bonus defense", 3);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Shrieking Gale": 30,
        "Tempest": 30,
    ]));
}
