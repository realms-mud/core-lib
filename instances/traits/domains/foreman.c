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
        addSpecification("type", "professional");
        addSpecification("name", "foreman");
        addSpecification("description", "You are able to lead building projects");
        addSpecification("root", "foreman");
        addSpecification("opinion", 5);

        "baseTrait"::reset(arg);
    }
}
