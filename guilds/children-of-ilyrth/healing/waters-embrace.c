//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Waters Embrace");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to enhance their healing magic. The embrace of Ilyrth's "
        "waters grows stronger, amplifying the restorative effects of all "
        "healing spells.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 3 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/soothing-touch.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus healing", 3);
    addSpecification("bonus elemental water", 2);
    addSpecification("bonus heal spell points rate", 1);

    addSpecification("affected research", ([
        "Soothing Touch": 15
    ]));
    addSpecification("affected research type", "percentage");
}
