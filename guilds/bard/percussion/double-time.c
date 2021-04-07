//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Double Time");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "guilds/bard/compositions/root.c");
    addSpecification("composite type", "instrumental rhythm");
    addSpecification("composite class", "percussion");
    addSpecification("default composite description",
        "fast 16/16 beat");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating basic percussive elements for songs. "
        "For the next five rounds, all allies in the area are hasted.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 7 ]));

    addSpecification("limited by", ([
        "equipment":({ "instrument: percussion" }),
    ]));

    addPrerequisite("guilds/bard/percussion/drums-of-dedication.c",
        (["type":"research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 75);

    addSpecification("apply haste", 1);
    addSpecification("duration", 10);

    addSpecification("event handler", "percussiveBlastEvent");
    addSpecification("use composite message", "##InitiatorName## "
    "frantically ##Infinitive::tap## ##InitiatorPossessive## "
    "##InitiatorWeapon## in a ##CompositeSegment##.");
}
