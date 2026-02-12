//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Predatory Grace");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your movements in panther form become "
        "fluid and deadly, enhancing both offense and evasion.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 13
        ]));

    addPrerequisite("/guilds/therianthrope/panther/vicious-rake.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 4);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Pounce": 15,
        "Hamstring": 15,
        "Rending Claws": 15,
        "Savage Frenzy": 15,
        "Throat Tear": 15,
        "Predatory Surge": 15
    ]));
}
