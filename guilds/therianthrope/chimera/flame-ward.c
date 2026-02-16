//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flame Ward");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The fire within your chimera form "
        "infuses your hide with elemental resistance, granting powerful "
        "protection against the elements.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 37
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/bestial-rage.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist fire", 5);
    addSpecification("bonus resist cold", 3);
    addSpecification("bonus resist acid", 3);
    addSpecification("bonus soak", 3);
}
