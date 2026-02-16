//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Toxic Blood");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your connection to the serpent spirit "
        "infuses your blood with potent toxins, granting powerful resistance "
        "to poisons and enhancing your venomous nature.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 27
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/serpent-communion.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist poison", 5);
    addSpecification("bonus resist disease", 3);
    addSpecification("bonus resist acid", 3);
    addSpecification("bonus soak", 3);
}
