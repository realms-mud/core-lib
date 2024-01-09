//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fell Beat");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "/guilds/bard/compositions/root.c");
    addSpecification("composite type", "instrumental rhythm");
    addSpecification("composite class", "percussion");
    addSpecification("default composite description",
        "syncopated 12/8 groove");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating basic percussive elements for songs. "
        "For the next ten rounds, all enemies in the area are strengthened.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 15 ]));

    addSpecification("limited by", ([
        "equipment":({ "instrument: percussion" }),
    ]));

    addPrerequisite("/guilds/bard/percussion/drums-of-dedication.c",
        (["type":"research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 50);

    addSpecification("apply fortified", 1);
    addSpecification("duration", 20);

    addSpecification("event handler", "percussiveBlastEvent");
    addSpecification("use composite message", "##InitiatorName## "
    "##Infinitive::drum## ##InitiatorPossessive## "
    "##InitiatorWeapon## in a ##CompositeSegment##.");
}
