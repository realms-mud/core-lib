//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Killing Instinct");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The panther's killer instinct sharpens "
        "your strikes, finding weak points with preternatural accuracy.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 17
        ]));

    addPrerequisite("/guilds/therianthrope/panther/predatory-grace.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 2);
    addSpecification("bonus dodge", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Pounce": 20,
        "Hamstring": 20,
        "Rending Claws": 20,
        "Savage Frenzy": 20,
        "Throat Tear": 20,
        "Predatory Surge": 20
    ]));
}
