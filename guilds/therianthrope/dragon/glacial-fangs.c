//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Glacial Fangs");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The cold that courses through your "
        "dragon form intensifies, lending a freezing bite to every strike.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 33
        ]));

    addPrerequisite("/guilds/therianthrope/dragon/frost-claw.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 2);
    addSpecification("bonus attack", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Claw": 15,
        "Tail Lash": 10,
        "Frost Breath": 15,
        "Soul Freeze": 10,
        "Frozen Blight": 10,
        "Glacial Tempest": 10
    ]));
}
