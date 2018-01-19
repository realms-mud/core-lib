//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "bastard");
        addSpecification("description", "You were born out of wedlock of an illicit affair.");
        addSpecification("root", "bastard");
        addSpecification("opposing root", "legitimate");
        addSpecification("opinion", -25);
        addSpecification("penalty to persuasion", 5);
        addSpecification("research tree", "lib/instances/research/bastardResearchTree.c");
        addSpecification("cost", -1);
        "baseTrait"::reset(arg);
    }
}

