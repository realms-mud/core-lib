//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pressing of Hands");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of an advanced technique wherein the combatant first "
        "executes and undercut and then an over chop on an opponent's "
        "hands in an attempt to remove them.");

    addSpecification("limited by", (["equipment":({ "axe" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 30 ]));

    addPrerequisite("guilds/scion/paths/axe/forms/changing-through.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus axe", 1);
    addSpecification("bonus attack", 4);
}
