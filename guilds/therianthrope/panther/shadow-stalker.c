//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadow Stalker");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You move like a shadow in panther form, "
        "nearly invisible to your prey until it is too late.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 21
        ]));

    addPrerequisite("/guilds/therianthrope/panther/killing-instinct.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 1);
    addSpecification("bonus claw attack", 12);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Pounce": 25,
        "Hamstring": 25,
        "Rending Claws": 25,
        "Savage Frenzy": 25,
        "Throat Tear": 25,
        "Predatory Surge": 25
    ]));
}
