//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Draconic Efficiency");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your growing familiarity with the dragon "
        "form allows you to execute attacks with less effort.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 39
        ]));

    addPrerequisite("/guilds/therianthrope/dragon/dragons-fortitude.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Frost Claw": 5,
        "Tail Lash": 5,
        "Frost Breath": 10,
        "Soul Freeze": 10,
        "Frozen Blight": 10,
        "Glacial Tempest": 15
    ]));
}
