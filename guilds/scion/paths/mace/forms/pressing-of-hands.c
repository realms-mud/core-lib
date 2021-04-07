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
        "executes and undercut and then an over bash on an opponent's "
        "hands in an attempt to crush them.");

    addSpecification("limited by", (["equipment":({ "mace", "flail" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 30 ]));

    addPrerequisite("guilds/scion/paths/mace/forms/changing-through.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mace", 1);
    addSpecification("bonus flail", 1);
    addSpecification("bonus attack", 4);
}
