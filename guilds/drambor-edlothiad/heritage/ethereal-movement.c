//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ethereal Movement");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with ethereal movement, a technique "
        "that draws upon the boundary between the "
        "material and fey realms. The battlemage "
        "becomes partially insubstantial during "
        "combat, causing physical attacks to pass "
        "harmlessly through what appears to be "
        "solid flesh.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "spirit-of-the-wood.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 33
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 5);
    addSpecification("bonus resist physical", 3);
}
