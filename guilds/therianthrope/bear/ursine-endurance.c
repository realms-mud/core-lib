//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ursine Endurance");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your bear form grows more resilient, "
        "allowing you to shrug off injuries that would fell lesser creatures.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/bear/bear-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 5
        ]));

    addPrerequisite("/guilds/therianthrope/bear/thick-hide.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist physical", 1);
    addSpecification("bonus soak", 1);
    addSpecification("bonus hit points", 25);
}
