//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Goat's Tenacity");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The stubborn vitality of the goat aspect "
        "enhances your natural healing and defensive instincts while "
        "transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 29
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/chimeric-resilience.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points rate", 2);
    addSpecification("bonus heal stamina rate", 1);
    addSpecification("bonus defense", 2);
}
