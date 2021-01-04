//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "persona");
        addSpecification("name", "brown dragon");
        addSpecification("description", "You are a brown dragon.");
        addSpecification("root", "large creature persona");
        addSpecification("bonus resist earth", 75);
        "baseTrait"::reset(arg);
    }
}
