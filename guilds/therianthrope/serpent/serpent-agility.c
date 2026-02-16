//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Serpent Agility");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your serpent form grows more supple and "
        "elusive, allowing you to slither away from attacks with ease.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 11
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/scales-of-the-serpent.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus soak", 1);
    addSpecification("bonus hit points", 25);
}
