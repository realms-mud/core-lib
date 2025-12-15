//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mending Waters");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to enhance the mending properties of their healing magic. "
        "Ilyrth's waters flow more freely through the caster, amplifying "
        "their restorative abilities.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 7 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/healing-stream.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus healing", 3);
    addSpecification("bonus spellcraft", 2);

    addSpecification("affected research", ([
        "Soothing Touch": 15,
        "Healing Stream": 15,
        "Ocean Balm": 15
    ]));
    addSpecification("affected research type", "percentage");
}
