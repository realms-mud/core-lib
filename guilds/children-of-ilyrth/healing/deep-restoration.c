//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Deep Restoration");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of the deep ocean's restorative secrets. The caster "
        "learns to draw upon Ilyrth's most profound healing energies.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 13 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/restorative-torrent.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus body", 3);
    addSpecification("bonus anatomy and physiology", 1);
    addSpecification("bonus magical essence", 2);
    addSpecification("bonus heal hit points", 2);

    addSpecification("affected research", ([
        "Healing Stream": 20,
        "Ocean Balm": 20,
        "Lifegiving Waters": 20,
        "Wellspring of Life": 15
    ]));
    addSpecification("affected research type", "percentage");
}
