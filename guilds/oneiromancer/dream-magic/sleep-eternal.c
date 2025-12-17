//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sleep Eternal");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with "
        "understanding of the eternal sleep that awaits all mortal minds. "
        "This forbidden knowledge enhances the duration and potency of all "
        "debilitating effects.");

    addPrerequisite("/guilds/oneiromancer/dream-magic/eternal-slumber.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 63
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("bonus mind", 4);
    addSpecification("bonus senses", 3);
    addSpecification("bonus resist psionic", 10);
    addSpecification("bonus resist magical", 5);

    addSpecification("affected research", ([
        "Mind Fog": 25,
        "Sleep of Ages": 25,
        "Dream Shackles": 25,
        "Mind Prison": 25,
        "Eternal Slumber": 20,
        "Nightmare Cascade": 20,
        "Oneiric Apocalypse": 20
    ]));
    addSpecification("affected research type", "percentage");
}
