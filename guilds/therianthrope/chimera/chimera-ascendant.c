//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chimera Ascendant");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You have ascended beyond mere "
        "therianthropic transformation. Your chimera form is a force of "
        "primal nature itself, each of its three aspects striking with "
        "the fury of the ancients.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 61
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/eternal-chimera.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 175);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 4);
    addSpecification("bonus dodge", 6);
    addSpecification("bonus defense", 6);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Rending Claws": 30,
        "Gore": 30,
        "Fire Breath": 30,
        "Chimeric Rampage": 30,
        "Inferno": 30
    ]));
}
