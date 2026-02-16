//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Burning Blood");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The fire that churns within your chimera "
        "form intensifies, lending searing heat to your attacks.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 27
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/rending-claws.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 2);
    addSpecification("bonus attack", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Rending Claws": 15,
        "Gore": 10,
        "Fire Breath": 15,
        "Chimeric Rampage": 10,
        "Inferno": 10
    ]));
}
