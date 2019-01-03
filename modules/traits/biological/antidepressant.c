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
        addSpecification("type", "health");
        addSpecification("name", "on antidepressants");
        addSpecification("description", "You are on an antidepressant.");
        addSpecification("root", "biological");
        addSpecification("opinion", 5);
        addSpecification("duration", 300);
        "baseTrait"::reset(arg);
    }
}
