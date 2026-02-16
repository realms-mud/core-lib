//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frost Ward");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The cold within your dragon form "
        "infuses your scales with elemental resistance, granting powerful "
        "protection against the elements.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 41
        ]));

    addPrerequisite("/guilds/therianthrope/dragon/silver-aegis.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist cold", 5);
    addSpecification("bonus resist fire", 3);
    addSpecification("bonus resist air", 3);
    addSpecification("bonus soak", 3);
}
