//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Iron Fur");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your bear form's fur becomes almost "
        "metallic in its toughness, granting significant resistance to "
        "physical attacks.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/bear/bear-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 9
        ]));

    addPrerequisite("/guilds/therianthrope/bear/ursine-endurance.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus parry", 2);
    addSpecification("bonus resist physical", 2);
    addSpecification("bonus resist cold", 5);
}
