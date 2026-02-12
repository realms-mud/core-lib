//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blinding Speed");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your panther form strikes with impossible "
        "speed, reducing the recovery time between attacks.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 25
        ]));

    addPrerequisite("/guilds/therianthrope/panther/hunting-efficiency.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Pounce": 1,
        "Hamstring": 1,
        "Rending Claws": 2,
        "Savage Frenzy": 3,
        "Throat Tear": 5,
        "Shadow Stalk": 10,
        "Predatory Surge": 10
    ]));
}
