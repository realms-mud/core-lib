//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Techniques");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of general combat techniques.");

    addSpecification("limited by", (["equipment": ({ "soft leather",
        "hard leather", "scalemail", "chainmail", "splint armor",
        "plate armor" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus soak", 1);
}
