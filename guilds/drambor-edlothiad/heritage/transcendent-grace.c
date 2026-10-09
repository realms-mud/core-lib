//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Transcendent Grace");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with transcendent grace, the highest "
        "expression of elven physical perfection. "
        "Every movement becomes a work of art, "
        "every gesture carries lethal precision, "
        "and the body responds to will with an "
        "immediacy that defies natural law.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "timeless-wisdom.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 51
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dexterity", 2);
    addSpecification("bonus dodge", 5);
    addSpecification("bonus attack", 3);
}
