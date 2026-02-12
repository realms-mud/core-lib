//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Phantasmal Panther");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You channel the essence of ancient "
        "phantom cats, gaining preternatural combat ability while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 27
        ]));

    addPrerequisite("/guilds/therianthrope/panther/shadow-stalker.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dexterity", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 2);
    addSpecification("bonus defense", 3);

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
