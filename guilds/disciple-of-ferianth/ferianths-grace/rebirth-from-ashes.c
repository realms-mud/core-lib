//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rebirth from Ashes");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "Through Ferianth's ultimate blessing, "
        "the Exarch wraps themselves in divine flames that will restore "
        "them to life should they fall in battle. This protection lasts "
        "until triggered or it expires.");
    addSpecification("usage summary", "A protective ward that prevents "
        "death once when triggered");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/exarchs-blessing.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 41
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 500);
    addSpecification("stamina point cost", 200);
    addSpecification("cooldown", 3600);

    addSpecification("trait", 
        "/guilds/disciple-of-ferianth/ferianths-grace/rebirth-trait.c");

    addSpecification("event handler", "rebirthFromAshesEvent");
    addSpecification("command template", "rebirth from ashes");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## Ferianth's ultimate blessing. Divine flames "
        "envelop ##InitiatorPossessive## body, ready to restore life from death.");
}
