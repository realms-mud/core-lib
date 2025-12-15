//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Healing Maelstrom");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "the knowledge to channel healing energy as a maelstrom of "
        "restorative power. The caster's magic swirls with the intensity "
        "of a great ocean storm.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 33 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/divine-waters.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus healing", 5);
    addSpecification("bonus elemental water", 4);
    addSpecification("bonus divine essence", 3);
    addSpecification("bonus heal hit points", 3);

    addSpecification("affected research", ([
        "Wellspring of Life": 25,
        "Ilryth's Blessing" : 25,
        "Deluge of Healing" : 25,
        "Oceans Embrace" : 25,
        "Tidal Salvation" : 20
    ]));
    addSpecification("affected research type", "percentage");
}
