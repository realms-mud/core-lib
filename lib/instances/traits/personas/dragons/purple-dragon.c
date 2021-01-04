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
        addSpecification("name", "purple dragon");
        addSpecification("description", "You are a purple dragon.");
        addSpecification("root", "large creature persona");
        addSpecification("bonus resist psionic", 75);
        addSpecification("bonus resist electricity", 75);
        "baseTrait"::reset(arg);
    }
}
