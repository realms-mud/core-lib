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
        addSpecification("name", "Hunchback");
        addSpecification("description", "blah blah blah");
        addSpecification("root", "disfigured");
        addSpecification("opinion", 10);
        addSpecification("cost", 1);
        "baseTrait"::reset(arg);
    }
}
