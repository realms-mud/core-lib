//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Earthen Resilience");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your connection to the earth through "
        "the bear spirit grants powerful resistance to the elements.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/bear/bear-root.c"
        })
    ]));

    addPrerequisite("level",
        ([ "type":"level",
           "guild": "therianthrope",
           "value": 27
        ]));

    addPrerequisite("/guilds/therianthrope/bear/regeneration.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist poison", 2);
    addSpecification("bonus resist earth", 2);
    addSpecification("bonus resist cold", 2);
    addSpecification("bonus resist physical", 2);
    addSpecification("bonus soak", 3);
}
