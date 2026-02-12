//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hunting Efficiency");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your panther form executes attacks with "
        "minimal wasted energy, reducing the stamina cost of abilities.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 19
        ]));

    addPrerequisite("/guilds/therianthrope/panther/precision-strikes.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Pounce": 5,
        "Hamstring": 5,
        "Rending Claws": 8,
        "Savage Frenzy": 10,
        "Throat Tear": 15,
        "Predatory Surge": 10,
        "Shadow Stalk": 15
    ]));
}
