//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "The Way of the Mace");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to use maces and flails as their magical focus.");
    addSpecification("limited by", (["equipment":({ "mace", "flail" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus mace", 1);
    addSpecification("bonus flail", 1);
}
