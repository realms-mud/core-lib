//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stabbing");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to more effectively stab with swords.");
    addSpecification("limited by", (["equipment":({
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("guilds/scion/paths/sword/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 1);
    addSpecification("bonus damage", 1);
    addSpecification("equivalence", "stabbing");
}
