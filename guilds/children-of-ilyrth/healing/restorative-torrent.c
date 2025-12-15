//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Restorative Torrent");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to channel Ilyrth's power as a torrent of restoration. "
        "The caster's healing magic surges with increased intensity.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 11 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/tidal-renewal.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus healing", 3);
    addSpecification("bonus elemental water", 2);
    addSpecification("bonus heal hit points", 1);

    addSpecification("affected research", ([
        "Soothing Touch": 15,
        "Healing Stream": 20,
        "Ocean Balm": 20,
        "Healing Rain": 15,
        "Lifegiving Waters": 15
    ]));
    addSpecification("affected research type", "percentage");
}
