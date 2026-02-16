//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Feral Efficiency");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your growing familiarity with the chimera "
        "form allows you to execute attacks with less effort.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 31
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/goats-tenacity.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Rending Claws": 5,
        "Gore": 5,
        "Fire Breath": 10,
        "Chimeric Rampage": 10,
        "Inferno": 15
    ]));
}
