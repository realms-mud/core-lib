//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "A Miscreant");
    addSpecification("source", "background");
    addSpecification("description", "This skill provides the user with the "
        "basic knowledge learned from a life avoiding duty.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus wisdom", 1);
    addSpecification("bonus search", 1);
    addSpecification("bonus spot", 1);
    addSpecification("bonus open lock", 1);
    addSpecification("bonus move silently", 1);
    addSpecification("bonus listen", 1);
    addSpecification("bonus hide", 1);
    addSpecification("bonus disable traps", 1);
    addSpecification("bonus find traps", 1);
    addSpecification("bonus set traps and snares", 1);
    addSpecification("bonus tracking", 1);
    addSpecification("bonus perception", 1);
}
