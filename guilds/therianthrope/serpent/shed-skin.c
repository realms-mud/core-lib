//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shed Skin");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The regenerative power of the serpent "
        "spirit enhances your natural healing, allowing you to shed damaged "
        "scales and regrow them while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 15
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/serpent-agility.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points rate", 2);
    addSpecification("bonus heal stamina rate", 1);
    addSpecification("bonus defense", 2);
}
