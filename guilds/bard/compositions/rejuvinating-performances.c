//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rejuvinating Performances");
    addSpecification("source", "bard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of several advanced performance techniques that "
        "return a performer's energy.");

    addSpecification("limited by", ([
        "equipment": ({ "instrument: plucked", "instrument: bowed",
            "instrument: woodwind", "instrument: brass",
            "instrument: percussion" }) ]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "bard",
          "value": 23 ]));

    addPrerequisite("/guilds/bard/compositions/advanced-performances.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal spell points rate", 2);
    addSpecification("bonus heal stamina rate", 2);
    addSpecification("bonus heal spell points", 2);
    addSpecification("bonus heal stamina", 2);
}
