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
        addSpecification("type", "personality");
        addSpecification("name", "mordant");
        addSpecification("description", "You are a wholly detestable and "
            "utterly distasteful creature.");
        addSpecification("root", "harsh");
        addSpecification("opinion", -15);
        "baseTrait"::reset(arg);
    }
}
