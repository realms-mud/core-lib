//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Strike Speed");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your growing mastery of the serpent form "
        "allows you to strike with blinding speed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 25
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/strike-efficiency.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("bonus dodge", 2);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Fanged Bite": 1,
        "Constrict": 1,
        "Death Roll": 2,
        "Spit Venom": 2,
        "Miasma": 5
    ]));
}
