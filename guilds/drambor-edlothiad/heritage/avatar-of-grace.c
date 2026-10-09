//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of Grace");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the ultimate expression of elven "
        "heritage. The battlemage becomes a living "
        "avatar of grace and power, embodying every "
        "virtue of the elven race in a form that "
        "is as beautiful as it is terrifying to "
        "behold upon the battlefield.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "immortal-heritage.c",
        (["type": "research"]));
    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "blood-of-the-firstborn.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 69
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus strength", 2);
    addSpecification("bonus dexterity", 2);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus constitution", 2);
    addSpecification("bonus charisma", 2);
    addSpecification("bonus hit points", 50);
    addSpecification("bonus spell points", 50);
}
