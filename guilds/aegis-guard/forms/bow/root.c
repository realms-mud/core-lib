//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Rad ai Fain Cu");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of advanced bow techniques");

    addSpecification("limited by", (["equipment":({ "bow" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus bow", 1);
}
