//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "bastard");
    addSpecification("description", "You were born out of wedlock of an illicit affair.");
    addSpecification("root", "bastard");
    addSpecification("opposing root", "legitimate");
    addSpecification("opinion", -25);
    addSpecification("penalty to persuasion", 5);
    addSpecification("research tree", "/lib/instances/research/traits/bastardResearchTree.c");
    addSpecification("cost", -1);
}
