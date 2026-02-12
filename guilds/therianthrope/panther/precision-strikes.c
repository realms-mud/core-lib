//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Precision Strikes");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your mastery of the panther form enhances "
        "the precision and lethality of your attacks.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 15
        ]));

    addPrerequisite("/guilds/therianthrope/panther/rending-claws.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Pounce": 10,
        "Hamstring": 10,
        "Rending Claws": 10,
        "Savage Frenzy": 10,
        "Throat Tear": 5,
        "Predatory Surge": 5,
        "Shadow Stalk": 5
    ]));
}
