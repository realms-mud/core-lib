//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "strong");
        addSpecification("description", "You are a rather brawny person.");
        addSpecification("root", "strong");
        addSpecification("opposing root", "weak");
        addSpecification("opinion", 5);
        addSpecification("opposing opinion", -5);
        addSpecification("bonus strength", 2);
        addSpecification("cost", 1);
        "baseTrait"::reset(arg);
    }
}

