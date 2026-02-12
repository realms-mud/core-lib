//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lord of the Hunt");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your panther form reaches its ultimate "
        "potential, a perfect predator of unmatched speed and lethality.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 31
        ]));

    addPrerequisite("/guilds/therianthrope/panther/phantasmal-panther.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 50);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 5);
    addSpecification("bonus dodge", 5);
    addSpecification("bonus tail attack", 20);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Pounce": 30,
        "Hamstring": 30,
        "Rending Claws": 30,
        "Savage Frenzy": 30,
        "Throat Tear": 30,
        "Predatory Surge": 30
    ]));
}
