//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Strike Efficiency");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your growing familiarity with the serpent "
        "form allows you to execute attacks with less effort.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 19
        ]));

    addPrerequisite("/guilds/therianthrope/serpent/shed-skin.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Fanged Bite": 5,
        "Constrict": 5,
        "Death Roll": 10,
        "Spit Venom": 10,
        "Miasma": 15
    ]));
}
