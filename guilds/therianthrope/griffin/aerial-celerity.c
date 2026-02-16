//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aerial Celerity");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your growing mastery of the griffin form "
        "allows you to strike with blinding speed from the air.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 33
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/soaring-efficiency.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Talon Rake": 1,
        "Diving Strike": 1,
        "Shrieking Gale": 2,
        "Sky Hammer": 2,
        "Tempest": 5
    ]));
}
