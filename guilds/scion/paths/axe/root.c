//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "The Way of the Axe");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to use axes as their magical focus.");
    addSpecification("limited by", (["equipment":({
        "axe" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus axe", 1);
}
