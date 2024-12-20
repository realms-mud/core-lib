//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bardic Archery");
    addSpecification("source", "bard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of advanced archery techniques");

    addSpecification("limited by", (["equipment":({ "bow" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus bow", 1);
}
