//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Poise");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the innate poise of the elven "
        "people. Through meditation upon one's "
        "heritage, the battlemage awakens a deep "
        "bodily grace that makes every movement "
        "effortlessly precise and lends a quiet "
        "dignity to even the most violent combat.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "elven-reflexes.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 19
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dexterity", 1);
    addSpecification("bonus dodge", 3);
}
