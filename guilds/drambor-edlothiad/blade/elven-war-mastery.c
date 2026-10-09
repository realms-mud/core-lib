//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven War Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents complete "
        "mastery  of elven martial and magical techniques combined.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/battlemage-reflexes.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 41
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 8);
    addSpecification("bonus defense", 6);
    addSpecification("bonus damage", 5);
    addSpecification("bonus long sword", 8);
    addSpecification("bonus dodge", 3);
}
