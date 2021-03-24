//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        persistedActiveResearchItem::reset(arg);
        addSpecification("name", "Slow Dance");
        addSpecification("source", "bard");
        addSpecification("composite research",
            "guilds/bard/compositions/root.c");
        addSpecification("composite type", "instrumental rhythm");
        addSpecification("default composite description", 
            "slow 2/4 beat");

        addSpecification("description", "This skill provides the user with the "
            "knowledge of creating basic percussive elements for songs. "
            "For the next five rounds, all enemies in the area are slowed.");

        addPrerequisite("level", 
            (["type": "level", 
              "guild": "bard",
              "value": 7 ]));

        addSpecification("limited by", ([
            "equipment":({ "instrument: percussion" }),
        ]));

        addPrerequisite("guilds/bard/percussion/drums-of-doom.c",
            (["type":"research"]));

        addSpecification("scope", "area");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addSpecification("spell point cost", 75);

        addSpecification("apply slow", 1);
        addSpecification("duration", 10);

        addSpecification("event handler", "percussiveBlastEvent");
        addSpecification("use composite message", "##InitiatorName## "
        "languidly ##Infinitive::hit## ##InitiatorPossessive## "
        "##InitiatorWeapon## in a ##CompositeSegment##.");
    }
}
