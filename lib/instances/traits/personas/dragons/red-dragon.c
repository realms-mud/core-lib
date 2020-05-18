//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "persona");
        addSpecification("name", "red dragon");
        addSpecification("description", "You are a red dragon.");
        addSpecification("root", "large creature persona");
        addSpecification("bonus resist fire", 75);
        "baseTrait"::reset(arg);
    }
}
