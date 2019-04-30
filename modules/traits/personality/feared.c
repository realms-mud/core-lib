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
        addSpecification("type", "personality");
        addSpecification("name", "feared");
        addSpecification("description", "People regard you with a great "
            "deal of apprehension and fear.");
        addSpecification("root", "harsh");
        addSpecification("opposing root", "kind");
        addSpecification("opinion", -10);
        addSpecification("opposing opinion", -10);
        "baseTrait"::reset(arg);
    }
}
