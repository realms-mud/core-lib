//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Titanic Bear");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your bear form reaches its ultimate "
        "potential, growing to titanic proportions with devastating power "
        "and near-impenetrable defenses.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/bear/bear-root.c"
        })
    ]));

    addPrerequisite("level",
        ([ "type": "level",
           "guild": "therianthrope",
           "value": 31
        ]));

    addPrerequisite("/guilds/therianthrope/bear/primordial-beast.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 100);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 5);
    addSpecification("bonus soak", 5);
    addSpecification("bonus claw attack", 20);
}
