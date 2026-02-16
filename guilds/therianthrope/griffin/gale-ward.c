//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gale Ward");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your connection to the griffin spirit "
        "infuses your feathers with the power of the wind, granting "
        "resistance to elemental forces.");

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

    addPrerequisite("/guilds/therianthrope/griffin/aerial-vigilance.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist air", 5);
    addSpecification("bonus resist cold", 3);
    addSpecification("bonus resist fire", 3);
    addSpecification("bonus soak", 3);
}
