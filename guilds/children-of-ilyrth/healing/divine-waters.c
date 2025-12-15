//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Waters");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "access to the divine waters of Ilyrth's realm. The caster's "
        "connection to the goddess deepens, greatly enhancing all "
        "healing magic.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 25 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/tidal-mastery.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus healing", 5);
    addSpecification("bonus elemental water", 3);
    addSpecification("bonus divine essence", 3);
    addSpecification("bonus spell points", 15);

    addSpecification("affected research", ([
        "Healing Stream": 25,
        "Healing Rain": 25,
        "Wellspring of Life": 25,
        "Ilyriths Blessing": 25,
        "Deluge of Healing": 20,
        "Oceans Embrace": 15
    ]));
    addSpecification("affected research type", "percentage");
}
