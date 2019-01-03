//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "homely");
        addSpecification("description", "You are a rather unattractive person.");
        addSpecification("root", "homely");
        addSpecification("opposing root", "beautiful");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -5);
        addSpecification("penalty to charisma", 2);
        addSpecification("penalty to persuasion", 5);
        addSpecification("cost", -1);
        "baseTrait"::reset(arg);
    }
}

