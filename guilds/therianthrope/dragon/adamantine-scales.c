//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Adamantine Scales");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your silver scales harden to an "
        "adamantine density, granting exceptional protection against all "
        "forms of damage.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 45
        ]));

    addPrerequisite("/guilds/therianthrope/dragon/frost-ward.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus soak", 5);
    addSpecification("bonus defense", 4);
    addSpecification("bonus parry", 3);
    addSpecification("bonus resist physical", 3);
}
